//
//  WTWifiSDK.h
//  WTWifiSDK
//
//  Created by xuzhonglin on 2024/10/30.
//

#import <Foundation/Foundation.h>
#import "WTEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTWifiSDK : NSObject



/// if  you want to print logs,enabled = YES,else enabled =   NO
+ (void)setLoggingEnabled:(BOOL)enabled;

/**
 * Initialize the given SSID and return its suffix type.
 *
 * @param ssid The Wi-Fi SSID to analyze.
 */
+ (void)initSsid:(NSString *) ssid;

/**
 * Returns the actual SSID by removing a known suffix if present.
 *
 * @return The SSID string with the suffix removed if applicable.
 *
 * @discussion
 * This method calls [WTHelper removeSsidSuffix:] to strip specific
 * suffixes such as "AW" or "EL" from the end of the given SSID.
 * It is used to obtain the base SSID for further operations.
 */
+ (NSString *)getSn;

/**
 * 根据 SN 或带后缀的 SSID 计算 8 位 hex 密钥。
 *
 * @param input SN 或带后缀的 SSID（内部会先剥除已知后缀）。
 * @return 计算得到的 8 位 hex 密码字符串；输入过短时返回 nil。
 *
 * @discussion
 * 该方法转调内部工具类的密码生成逻辑，作为对外的纯计算接口，
 * 不依赖 initSsid: 的调用状态，可直接传入任意 SN 即时计算。
 */
+ (nullable NSString *)generatePwd:(NSString *)input;

/**
 * Retrieves the currently stored Wi-Fi password.
 *
 * @return The last stored Wi-Fi password string.
 *
 * @discussion
 * Use this method to get the Wi-Fi password that was previously
 * set locally, for example via `updatePassword:` after fetching
 * it from a cloud service or user input.
 */
+ (NSString *)getPassword;

/// Returns the type of the current SSID suffix as a WTWIFIType enum value.
///
/// @return A WTWIFIType value indicating the type of the current SSID:
///         - WTWIFITypeEtouchOld: The SSID ends with the Etouch old suffix.
///         - WTWIFITypeEtouch18031: The SSID ends with the Etouch 18031 suffix.
///         - WTWIFITypeSelf: The SSID ends with the Self suffix.
///         - WTWIFITypeUnknown: The SSID does not match any known suffix.
///
/// @discussion
/// This method checks the current SSID stored in WTConstants and determines
/// its suffix type using the WTHelper utility class.
+ (WTWIFIType )getSsidType;

/**
 * Updates the stored Wi-Fi password with a new value.
 *
 * @param newPassword The new Wi-Fi password to store.
 *
 * @discussion
 * This method can be used to update the local password value,
 * for example after retrieving the latest password from a cloud service
 * or a secure backend. Other classes can then access the updated password
 * via the appropriate getter.
 */
+ (void)updatePassword:(NSString *)newPassword;

/// Resets the default password used by the Wi-Fi SDK.
//////
/// @discussion
/// This method updates the default Wi-Fi password used internally by the SDK.
/// It can be called, for example, when retrieving a new password from a server
/// or when the user changes the default password manually.
///
/// The updated password will be used for subsequent Wi-Fi operations
/// that require a default password.
+ (void)resetDefaultPassword;

/// Returns the current list of SSIDs.
/// @return An array of SSID strings.
+ (NSArray *)getSsidArray;


@end

NS_ASSUME_NONNULL_END
