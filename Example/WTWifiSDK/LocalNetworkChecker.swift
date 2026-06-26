import Foundation
import Network

/// Uses bonjour networking to relialby check if user has granted local network access
/// How to use:

/// Add LocalNetworkAuthorization class to your project
/// Open .plist file and add "_bonjour._tcp", "_lnp._tcp.", as a values under "Bonjour services"
/// Call requestAuthorization() to trigger the prompt or get the authorization status if it already been approved/denied
/// about the author: https://stackoverflow.com/a/67758105/705761
@objc public class LocalNetworkAuthBridge: NSObject {
    @objc public static func requestAuthorization(_ completion: @escaping (Bool) -> Void) {
        if #available(iOS 13.0, *) {
            let checker = LocalNetworkAuthorization()
            checker.requestAuthorization { granted in
                completion(granted)
            }
        } else {
            // Fallback on earlier versions
            completion(false)
        }
    }
}

@available(iOS 13.0, *)
public class LocalNetworkAuthorization: NSObject, @unchecked Sendable {
    private var browser: NWBrowser?
    private var netService: NetService?
    private var completion: ((Bool) -> Void)?

    
    public func requestAuthorization(completion: @escaping (Bool) -> Void) {
        self.completion = completion
        
        // Create parameters, and allow browsing over peer-to-peer link.
        let parameters = NWParameters.tcp
        parameters.includePeerToPeer = true
        
        // Browse for a custom service type.
        let browser = NWBrowser(for: .bonjour(type: "_http._tcp", domain: nil), using: .tcp)
        self.browser = browser
        browser.stateUpdateHandler = { [weak self] newState in
            guard let self = self else { return }
            switch newState {
            case .failed(let error):
                print(error.localizedDescription)
            case .ready, .cancelled:
                break
            case let .waiting(error):
                print("Local network permission has been denied: \(error)")
                self.reset()
                DispatchQueue.main.async {
                    self.completion?(false)
                }
            default:
                break
            }
        }
        
        self.netService = NetService(domain: "local.", type:"_lnp._tcp.", name: "LocalNetworkPrivacy", port: 1100)
        self.netService?.delegate = self
        
        self.browser?.start(queue: .main)
        self.netService?.publish()
    }
    
    
    private func reset() {
        self.browser?.cancel()
        self.browser = nil
        self.netService?.stop()
        self.netService = nil
    }
}

@available(iOS 13.0, *)
extension LocalNetworkAuthorization : NetServiceDelegate {
    public func netServiceDidPublish(_ sender: NetService) {
        self.reset()
        print("Local network permission has been granted")
        DispatchQueue.main.async {
            self.completion?(true)
        }
    }
}
