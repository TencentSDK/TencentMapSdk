//
//  QOverspeedInfo.h
//  QMapKit
//
//  Created by NancyNan on 2016/10/27.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger) {
    QOverspeedTypeCamera = 0,//电子眼超速
    QOverspeedTypeRoad,//道路超速
} QOverspeedType;

@interface QOverspeedInfo : NSObject

/**
 限速值，单位: 公里／小时
 */
@property (nonatomic, assign) NSInteger limitSpeed;

/**
 当前速度值，单位: 公里／小时
 */
@property (nonatomic, assign) CGFloat currentSpeed;

/**
 超速类型
 */
@property (nonatomic, assign) QOverspeedType type;

@end
