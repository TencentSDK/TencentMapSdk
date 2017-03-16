//
//  QMapViewController.m
//  TencentMapSdk
//
//  Created by CleverZhang on 03/16/2017.
//  Copyright (c) 2017 CleverZhang. All rights reserved.
//
#import <QMapView.h>
#import "QMapViewController.h"

@interface QMapViewController ()
@property(nonatomic, strong)QMapView* mapView;
@end

@implementation QMapViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    self.mapView  = [[QMapView alloc]initWithFrame:self.view.bounds];
    [self.view addSubview:self.mapView];
}

@end
