//
//  DDLine.h
//  QMapKit
//
//  Created by cleverzhang on 15/1/19.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "QTypes.h"
#import "QRouteSearch.h"
/*
 *
 * 分段样式
 */
typedef enum  {
    DCLineTypeShiXian       = 0, // 实线
    DCLineTypeXuXian    	   = 1, // 虚线
}DCLineType;


@interface DDLine : NSObject
@property(nonatomic, strong) QPlaceInfo* startPoint;  //此分段起点
@property(nonatomic, strong) QPlaceInfo* endPoint;    //此分段终点
@property(nonatomic, assign) DCLineType lineType;    //此分段样式(实线/虚线)
@property(nonatomic, assign) QMRouteColor lineColor;   //此分段颜色
@property(nonatomic, assign) CGFloat lineWith;   //此分段线宽,预留接口暂时不起作用
@property(nonatomic, assign) BOOL bPass;
@end
