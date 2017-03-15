//
//  QHeatTileNode.h
//  QMapKit
//
//  Created by tabsong on 15/8/19.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QHeatTileNodeProtocol.h"

// 热力图节点数据.
@interface QHeatTileNode : NSObject <QHeatTileNodeProtocol>

/*!
 *  @brief  节点的坐标.
 */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/*!
 *  @brief  节点的热力值.
 */
@property (nonatomic, assign) CGFloat value;

@end
