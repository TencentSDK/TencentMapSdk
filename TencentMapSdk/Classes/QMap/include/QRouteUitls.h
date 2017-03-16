//
//  QRouteUitls.h
//  QMapKit
//
//  Created by weizhengli on 2016.06.07.
//  Copyright 2016 Tencent. All rights reserved.
//


#import "QRouteInfo.h"

@interface QRouteUitls : NSObject

/**
 *	计算点串组成的bounds
 *
 *  @param  arrPoint 点集合
 *  @return 点串组成的bounds
 */
+ (QMapRect)visibleRect:(NSArray*)arrPoint;

@end
