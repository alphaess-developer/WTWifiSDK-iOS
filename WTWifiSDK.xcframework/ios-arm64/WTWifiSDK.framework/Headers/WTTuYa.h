//
//  WTTuYa.h
//  WTWifiSDK
//
//  Created by xuzhonglin on 2024/10/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WTTuYa : NSObject

+ (instancetype)sharedInstance;
/**
 * Initializes an instance with the specified key, secret, and debug mode.
 *
 * @param key      The unique key used for authentication or identification.
 *
 * @param secret   The secret corresponding to the key, used for secure operations.
 *
 * @param isDebug  A boolean indicating whether to enable debug mode.
 *                 If set to YES, additional logging and diagnostic information may be provided.
 *
 */
- (void)initWithKey:(NSString *)key secret:(NSString *)secret debug:(BOOL)isDebug;

/**
 Tuya user login or registration.

 @param countryCode  The country code, for example, "86" for China.
 
 @param uid          The anonymous ID, a unique identifier for the user.
                     It doesn't need to follow a specific format and serves as the user's unique identity.
 
 @param password     A random identifier associated with the account ID.
                     This identifier should remain consistent for the same account ID,
                     and it is not the user's actual password.
 
 @param createHome   A boolean flag indicating whether to create a default home for the user.
 
 @param success      A callback block executed when the request is successful.
                     It receives a result object containing the response data.
 
 @param failure      A callback block executed when the request fails.
                     It receives an NSError object describing the failure reason.
 */
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              password:(NSString *)password
                            createHome:(BOOL)createHome
                               success:(void (^)(id result))success
                               failure:(void (^)(NSError *error))failure;

/**
 * Retrieves a token for a Tuya device.
 *
 * @param homeId   The unique identifier of the user's home.
 *                 This is used to associate the token request with a specific home setup in the Tuya system.
 *
 * @param success  A callback block executed when the token retrieval is successful.
 *                 It receives a string representing the token for the device.
 *
 * @param failure  A callback block executed when the token retrieval fails.
 *                 It receives an NSError object describing the failure reason.
 */
- (void)getDeviceTokenWithHomeId:(long long)homeId success:(void(^)(NSString *token))success
                                failure:(void(^)(NSError *error))failure;



@end

NS_ASSUME_NONNULL_END
