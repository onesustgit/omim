#import "MWMBottomMenuView.h"
#import "MWMCircularProgress.h"

#import "MWMNavigationDashboardEntity.h"
#import "MWMNavigationDashboardInfoProtocol.h"
#import "MWMNavigationViewProtocol.h"
#import "MWMRoutePreview.h"
#import "MWMTaxiPreviewDataSource.h"

#include "Framework.h"
#include "platform/location.hpp"

typedef NS_ENUM(NSUInteger, MWMNavigationDashboardState) {
  MWMNavigationDashboardStateHidden,
  MWMNavigationDashboardStatePrepare,
  MWMNavigationDashboardStatePlanning,
  MWMNavigationDashboardStateError,
  MWMNavigationDashboardStateReady,
  MWMNavigationDashboardStateNavigation
};

@protocol MWMNavigationDashboardManagerProtocol<MWMNavigationViewProtocol>

- (void)setMenuState:(MWMBottomMenuState)menuState;
- (void)setMenuRestoreState:(MWMBottomMenuState)menuState;
- (void)setRoutingErrorMessage:(NSString *)errorMessage;
- (MWMTaxiCollectionView *)taxiCollectionView;

@end

@interface MWMNavigationDashboardManager : NSObject

+ (MWMNavigationDashboardManager *)manager;

@property(nonatomic, readonly) MWMNavigationDashboardEntity * entity;
@property(nonatomic, readonly) MWMRoutePreview * routePreview;
@property(nonatomic) MWMNavigationDashboardState state;
@property(nonatomic) MWMTaxiPreviewDataSource * taxiDataSource;
@property(weak, nonatomic, readonly) id<MWMNavigationDashboardManagerProtocol> delegate;
@property(nonatomic) CGFloat topBound;
@property(nonatomic) CGFloat leftBound;

- (instancetype)init __attribute__((unavailable("init is not available")));
- (instancetype)initWithParentView:(UIView *)view
                          delegate:(id<MWMNavigationDashboardManagerProtocol>)delegate;
- (void)updateFollowingInfo:(location::FollowingInfo const &)info;
- (void)updateDashboard;
- (void)setRouteBuilderProgress:(CGFloat)progress;
- (void)mwm_refreshUI;
- (void)setMapSearch;

- (void)addInfoDisplay:(id<MWMNavigationDashboardInfoProtocol>)infoDisplay;

- (void)updateStartButtonTitle:(UIButton *)startButton;

- (void)onRoutePointsUpdated;

@end
