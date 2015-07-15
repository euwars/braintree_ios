#import <Foundation/Foundation.h>

#import "BTHTTPErrors.h"
#import "BTJSON.h"

@class BTHTTPResponse;

typedef void (^BTHTTPCompletionBlock)(BTJSON *body, NSHTTPURLResponse *response, NSError *error);

/// Key for userInfo dictionary that contains the NSHTTPURLResponse from server when it returns an HTTP error
extern NSString * const BTHTTPURLResponseKey;
/// Key for userInfo dictionary that contains the BTJSON body of the HTTP error response
extern NSString * const BTHTTPJSONResponseBodyKey;

@interface BTHTTP : NSObject<NSCopying>

/// An optional array of pinned certificates, each an NSData instance
/// consisting of DER encoded x509 certificates
@property (nonatomic, strong) NSArray *pinnedCertificates;

- (instancetype)initWithBaseURL:(NSURL *)URL authorizationFingerprint:(NSString *)authorizationFingerprint NS_DESIGNATED_INITIALIZER;

// For testing
@property (nonatomic, strong) NSURLSession *session;
@property (nonatomic, readonly, strong) NSURL *baseURL;

/// Queue that callbacks are dispatched onto, main queue if not otherwise specified
@property (nonatomic, strong) dispatch_queue_t dispatchQueue;

- (void)GET:(NSString *)endpoint completion:(BTHTTPCompletionBlock)completionBlock;
- (void)GET:(NSString *)endpoint parameters:(NSDictionary *)parameters completion:(BTHTTPCompletionBlock)completionBlock;

- (void)POST:(NSString *)endpoint completion:(BTHTTPCompletionBlock)completionBlock;
- (void)POST:(NSString *)endpoint parameters:(NSDictionary *)parameters completion:(BTHTTPCompletionBlock)completionBlock;

- (void)PUT:(NSString *)endpoint completion:(BTHTTPCompletionBlock)completionBlock;
- (void)PUT:(NSString *)endpoint parameters:(NSDictionary *)parameters completion:(BTHTTPCompletionBlock)completionBlock;

- (void)DELETE:(NSString *)endpoint completion:(BTHTTPCompletionBlock)completionBlock;
- (void)DELETE:(NSString *)endpoint parameters:(NSDictionary *)parameters completion:(BTHTTPCompletionBlock)completionBlock;

@end
