//
//  QMapBaseDemoViewController.m
//  QMapKitDemoNew
//
//  Created by ZhangChao on 2017/3/6.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import "QMapBaseDemoViewController.h"
#import <QMapView.h>
@interface QMapBaseDemoViewController ()
@property (weak, nonatomic) IBOutlet QMapView *mapView;

@end

@implementation QMapBaseDemoViewController

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


- (IBAction)toggleCompassAction:(id)sender {
    self.mapView.showsCompass = !self.mapView.showsCompass;
}


- (IBAction)toggle3DAction:(id)sender {
    self.mapView.show3D = !self.mapView.show3D;
}

- (IBAction)toggleTrafficAction:(id)sender {
    switch (self.mapView.userTrackingMode)
    {
        case QMUserTrackingModeNone:
        default:
        {
            //_mapView.userTrackingMode = QMUserTrackingModeFollow;
            [self.mapView setUserTrackingMode:QMUserTrackingModeFollow animated:NO];
            break;
        }
        case QMUserTrackingModeFollow:
        {
            if ([CLLocationManager headingAvailable])
                // _mapView.userTrackingMode = QMUserTrackingModeFollowWithHeading;
                [self.mapView setUserTrackingMode:QMUserTrackingModeFollowWithHeading animated:NO];
            else
                //_mapView.userTrackingMode = QMUserTrackingModeNone;
                [self.mapView setUserTrackingMode:QMUserTrackingModeNone animated:NO];
            
            break;
        }
        case QMUserTrackingModeFollowWithHeading:
        {
            // _mapView.userTrackingMode = QMUserTrackingModeNone;
            [self.mapView setUserTrackingMode:QMUserTrackingModeNone animated:NO];
            break;
        }
    }
}

- (IBAction)changeLanguageAction:(id)sender {
}


- (IBAction)adjustScaleViewPosition:(id)sender {
    int xOffset = arc4random_uniform(100) - 50;
    int yOffset = arc4random_uniform(100) - 50;
    CGPoint offset = CGPointMake(xOffset, yOffset);
    [self.mapView setScaleViewOffset:offset];
}

- (IBAction)changeMapStyleAction:(id)sender {
    UIButton* button = (UIButton*)sender;
    if (self.mapView.mapType==QMapTypeStandard) {
        [button setTitle:@"道路图" forState:UIControlStateNormal];
        self.mapView.mapType = QMapTypeSatellite;
    }
    else
    {
        [button setTitle:@"卫星图" forState:UIControlStateNormal];
        self.mapView.mapType = QMapTypeStandard;
    }
    
}
- (IBAction)toggleUserLocation:(id)sender {
    self.mapView.showsUserLocation = !self.mapView.showsUserLocation;
}

@end
