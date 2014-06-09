#import "BTClient+Testing.h"

SpecBegin(BTClientToken_Integration)

describe(@"initForTestingWithConfiguration:", ^{
    it(@"returns a preconfigured client with a version 2 client token", ^AsyncBlock{
        [BTClient testClientWithConfiguration:@{
           BTClientTestConfigurationKeyMerchantIdentifier: @"integration_merchant_id",
           BTClientTestConfigurationKeyPublicKey: @"integration_public_key",
           BTClientTestConfigurationKeyCustomer: @"myCustomer",
           BTClientTestConfigurationKeySharedCustomerIdentifier: @"testing",
           BTClientTestConfigurationKeySharedCustomerIdentifierType: @"testing",
           BTClientTestConfigurationKeyClientTokenVersion: @2,
           BTClientTestConfigurationKeyBaseUrl: @"http://example.com/",
           BTClientTestConfigurationKeyAnalytics: @{BTClientTestConfigurationKeyBatchSize: @5}
           } completion:^(BTClient *client) {
               expect(client).to.beKindOf([BTClient class]);
               expect(client.challenges).to.equal([NSSet setWithArray:@[@"cvv", @"postal_code"]]);
               done();
           }];
    });

    it(@"returns a preconfigured client based on a version 1 client token", ^AsyncBlock{
        [BTClient testClientWithConfiguration:@{
           BTClientTestConfigurationKeyMerchantIdentifier: @"integration_merchant_id",
           BTClientTestConfigurationKeyPublicKey: @"integration_public_key",
           BTClientTestConfigurationKeyCustomer: @"myCustomer",
           BTClientTestConfigurationKeySharedCustomerIdentifier: @"testing",
           BTClientTestConfigurationKeySharedCustomerIdentifierType: @"testing",
           BTClientTestConfigurationKeyClientTokenVersion: @1,
           BTClientTestConfigurationKeyBaseUrl: @"http://example.com/",
           } completion:^(BTClient *client) {
               expect(client).to.beKindOf([BTClient class]);
               expect(client.challenges).to.equal([NSSet setWithArray:@[@"cvv", @"postal_code"]]);
               done();
           }];
    });
});

SpecEnd
