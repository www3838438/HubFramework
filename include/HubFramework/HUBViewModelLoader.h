#import <Foundation/Foundation.h>

@protocol HUBViewModelLoader;
@protocol HUBViewModel;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Delegate protocol for `HUBViewModelLoader`
 *
 *  Conform to this protocol in a custom object to get notified when a view model was loaded, or if an
 *  error occured in the loading process.
 */
@protocol HUBViewModelLoaderDelegate <NSObject>

/**
 *  Sent to a view model loader's delegate when a view model was loaded
 *
 *  @param viewModelLoader The view model loader that loaded a view model
 *  @param viewModel The view model that was loaded
 */
- (void)viewModelLoader:(id<HUBViewModelLoader>)viewModelLoader didLoadViewModel:(id<HUBViewModel>)viewModel;

/**
 *  Sent to a view model loader's delegate when an error occured, causing the loader to fail
 *
 *  @param viewModelLoader The view model loader that encountered the error
 *  @param error The error that was encountered
 */
- (void)viewModelLoader:(id<HUBViewModelLoader>)viewModelLoader didFailLoadingWithError:(NSError *)error;

@end

/**
 *  Protocol defining the public API of a view model loader
 *
 *  You don't conform to this protocol yourself, instead the Hub Framework will create objects conforming to
 *  this protocol internally. This API is currently not accessible from outside of the Hub Framework, but will
 *  be soon as part of the external data API.
 */
@protocol HUBViewModelLoader <NSObject>

/**
 *  The view model loader's delegate
 *
 *  Assign a custom object to this property to get notified of events. See `HUBViewModelLoaderDelegate` for
 *  more information.
 */
@property (nonatomic, weak, nullable) id<HUBViewModelLoaderDelegate> delegate;

/**
 *  Load a view model using this loader
 *
 *  Depending on the current connectivity state (determined by the current `HUBConnectivityStateResolver`),
 *  and the configuration of the feature that his view model is serving, a combination of remote and local
 *  content will be loaded using the respective content providers.
 *
 *  The loader will notify its delegate once the operation was completed or if it failed.
 *  See `HUBViewModelLoaderDelegate` for more information.
 */
- (void)loadViewModel;

@end

NS_ASSUME_NONNULL_END