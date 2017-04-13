//
//  QMapNavigationDemoViewController.m
//  QMapKitDemoNew
//
//  Created by ZhangChao on 2017/3/6.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import "QMapNavigationDemoViewController.h"
#import <QMapKit.h>
@interface QMapNavigationDemoViewController ()<QSearchDelegate>
@property (weak, nonatomic) IBOutlet QMapView *mapView;
@property(nonatomic,strong)QSearch* search;
@end

@implementation QMapNavigationDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)initNav
{
    self.search.delegate = nil;
    self.search = nil;
    self.search = [[QSearch alloc] init];
    self.search.delegate = self;
    
    self.search.qOrderExtraInfo = [[QOrderExtraInfo alloc]init];
    self.search.qOrderExtraInfo.order_id = @"123456";
    self.search.qOrderExtraInfo.nav_scene = 2;
    self.search.qOrderExtraInfo.biz_type = @"kuaiche_test";
    
}


- (IBAction)calculateRoute:(id)sender {
    [self initNav];
    QPlaceInfo* _start = [[QPlaceInfo alloc]init];
    _start.name = @"第三级";
    if (![_mapView showsUserLocation]) {
        [_mapView setShowsUserLocation:YES];
    }
    CGFloat fOffsetLat = 0.01f;
    CGFloat fOffsetLon = 0.01f;
    int nStartOffset = 0;
    int nEndOffset = 20;
    CGFloat fLat = 39.982627;
    CGFloat fLon = 116.312;
    if (YES)
    {
        _start.coordinate = CLLocationCoordinate2DMake(39.843438620802675,116.28920495510101);
    }
    else
    {
        _start.coordinate = [_mapView userLocation].location;//CLLocationCoordinate2DMake(40.0390582485,116.4053244052);//
    }
    
    _start.city = @"北京市";
    
    QPlaceInfo* _end = [[QPlaceInfo alloc]init];
    _end.name = @"望春园";

    _end.coordinate = CLLocationCoordinate2DMake(fLat + (fOffsetLat * nEndOffset),fLon + (fOffsetLon * nEndOffset));
    _end.city = @"北京市";
    QDriveSearchType searchType;
    searchType = QDriveSearchShortTime;//QDriveSearchShortDistance;//QDriveSearchShortCut,QDriveSearchNoSubway


    [self.search clearPoints];
    self.search.notoll = YES;
    self.search.traffic = NO;
    self.search.angle = 48;
    [self.search navRouteSearchWithLocation:_start end:_end withDriveSearchType:searchType noHighway:YES];
    
}

- (IBAction)startNavigation:(id)sender {
    [_mapView startNavigation:YES];
    [ [ UIApplication sharedApplication] setIdleTimerDisabled:YES ] ;
}

- (IBAction)endNavigation:(id)sender {
    [_mapView stopNavigation];
    [ [ UIApplication sharedApplication] setIdleTimerDisabled:NO ] ;
}


//导航状态下如果拖动屏幕，会暂时结束跟随模式，可以用此方法回到导航状态
- (IBAction)continueNavigation:(id)sender {
    [_mapView continueNavigation];
}


#pragma mark -  delegate 
-(void)notifyNavRouteSearchResult:(RouteResult *)routeSearchResult
{
    NSLog(@"notifyNavRouteSearchResult");
    
    routeSearchResult.bHidePoints = NO;
    routeSearchResult.bHideArrow = NO;
    if ([routeSearchResult isTypeCar]) {
        if (routeSearchResult.routes.count > 0) {
            {
                routeSearchResult.selectedRouteIndex=0; // 默认 0
                [_mapView showSearchRoute:routeSearchResult routeColor:RC_TRAFFIC]; // RC_TRAFFIC 路况颜色

            }
        }
    }
    
}

-(void)returnTTSValue:(QttsParam *)ttsParam
{
}

- (void)triggerOverspeed:(QOverspeedInfo *)overspeedInfo {
    NSLog(@"=======triggerOverspeed limitSpeed:%ld currentSpeed:%lf type:%ld", overspeedInfo.limitSpeed, overspeedInfo.currentSpeed, overspeedInfo.type);
}

-(void)updateRouteResult:(QMRoute *)routeResult
{
    //    NSLog(@"updateRouteResult");
}

-(void)userNavigationEnd:(BOOL)bFinished;
{
    [_mapView stopNavigation];
}
-(void)notifyNavRouteSearchDidFail
{
    NSLog(@"notifyNavRouteSearchDidFail");
}

@end
