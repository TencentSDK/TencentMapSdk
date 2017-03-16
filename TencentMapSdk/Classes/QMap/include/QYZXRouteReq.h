//
//  QYZXRouteReq.h
//  QMapKit
//
//  Created by sarah on 16/5/15.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QMapView.h"

/**
 *  对应于 DriverOrderRouteReq 中需要上层传入的参数
message DriverOrderRouteReq{
    required string orderId = 1;
    required string phoneNum = 2;
    required int32 orderStage = 3;
    required int32 bizType = 4;
    required DoublePoint startPoint = 5;
    required int32 startPointSpeed = 6;
    required int32 startPointDirection = 7;
    required int32 startPointAccuracy = 8;
    required DoublePoint endPoint = 9;
    required int32 eventType = 10;//0:普通，1:偏航,2:更改目的地
    required uint64 timestamp = 11;
    required string imei = 12;
    required bytes routeEngineReqPack = 13;
   	required string version = 14;
    required string ticket = 15;
    optional uint64 passengerId = 16;
    optional uint64 driverId = 17;
    optional string traverId = 18;
    optional uint64 lastDiDiRouteId = 19;//DIDI routeid
}*/

@interface QYZXRouteReq : NSObject

@property(nonatomic) int navScene;

@property (nonatomic, copy) NSString *bizType;//业务类型

@property (nonatomic, strong) NSString* phoneNum;
@property(nonatomic, assign) CLLocationCoordinate2D startPoint;
@property (nonatomic, assign) int startPointSpeed;
@property (nonatomic, assign) int startPointDirection;
@property (nonatomic, assign) int startPointAccuracy;
@property(nonatomic, assign) CLLocationCoordinate2D endPoint;

@property (nonatomic, strong) NSString* ticket;
@property (nonatomic, assign) UInt64 passengerId;
@property (nonatomic, assign) UInt64 driverId;
@property (nonatomic, strong) NSString* traverId;
@end
