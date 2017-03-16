//
//  QHeatTileNodeProtocol.h
//  QMapKit
//
//  Created by tabsong on 15/8/19.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol QHeatTileNodeProtocol <NSObject>

@required

/*!
 *  @brief  坐标.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/*!
 *  @brief  热力值.
 */
@property (nonatomic, readonly) CGFloat value;

@end
