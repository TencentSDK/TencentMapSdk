//
//  QUilityFunction.h
//  SOSOMapAPI
//
//  Created by wei lv on 12-6-3.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef SOSOMapAPI_QUilityFunction_h
#define SOSOMapAPI_QUilityFunction_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "QGeometry.h"
#import "QTypes.h"
#ifdef __cplusplus
extern "C"
{
#endif

QMapRect _QMCoordinateRegionForMapRect(QCoordinateRegion region);

NSString* _QChannelIdentifier(NSString* appKey,NSString* appName);

//获取两个点的夹角
double _QGetAngle(double x1,double y1, double x2, double y2);

void _QNetWorkStart();
void _QNetWorkStop();

//设置网络状态
void _QNetWorkSetStatus(QNetworkStatus status);
//获取当前网络状态
QNetworkStatus _QNetWorkGetStatus();

BOOL _QNetWorkIsNotReachable();//网络是否不可达
BOOL _QNetWorkIs3GNet();//是否是WLAN
BOOL _QNetWorkIsWifiNet();//是否是Wi-Fi网络
#ifdef __cplusplus
}
#endif

#endif
