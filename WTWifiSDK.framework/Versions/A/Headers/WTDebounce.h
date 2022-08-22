//
//  WTDebounce.h
//  WTWifiSDK
//
//  Created by cavan on 2022/8/17.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - public class

typedef NS_ENUM(NSUInteger, WTDebounceMode) {
    WTDebounceModeTrailing,        //invoking on the trailing edge of the timeout
    WTDebounceModeLeading,         //invoking on the leading edge of the timeout
};

typedef void(^WTDebounceTaskBlock)(void);

@interface WTDebounce : NSObject

/// Initialize a debounce object, the debounce mode is the default WTDebounceModeTrailing, the execution queue defaults to the main queue. Note that debounce is for the same WTDebounce object, and different WTDebounce objects do not interfere with each other
/// @param interval debounce time interval, unit second
/// @param taskBlock the task to be debounced
- (instancetype)initWithInterval:(NSTimeInterval)interval
                       taskBlock:(WTDebounceTaskBlock)taskBlock;

/// Initialize a debounce object, the debounce mode is the default WTDebounceModeTrailing. Note that debounce is for the same WTDebounce object, and different WTDebounce objects do not interfere with each other
/// @param interval debounce time interval, unit second
/// @param queue execution queue, defaults the main queue
/// @param taskBlock the task to be debounced
- (instancetype)initWithInterval:(NSTimeInterval)interval
                         onQueue:(dispatch_queue_t)queue
                       taskBlock:(WTDebounceTaskBlock)taskBlock;

/// Initialize a debounce object. Note that debounce is for the same WTDebounce object, and different WTDebounce objects do not interfere with each other
/// @param debounceMode the debounce mode, defaults WTDebounceModeTrailing
/// @param interval debounce time interval, unit second
/// @param queue execution queue, defaults the main queue
/// @param taskBlock the task to be debounced
- (instancetype)initWithDebounceMode:(WTDebounceMode)debounceMode
                            interval:(NSTimeInterval)interval
                             onQueue:(dispatch_queue_t)queue
                           taskBlock:(WTDebounceTaskBlock)taskBlock;


/// debouncing call the task
- (void)call;


/// When the owner of the WTDebounce object is about to release, call this method on the WTDebounce object first to prevent circular references
- (void)invalidate;

@end

#pragma mark - private classes

@interface WTDebounceTrailing : WTDebounce

@end

@interface WTDebounceLeading : WTDebounce

@end


NS_ASSUME_NONNULL_END

