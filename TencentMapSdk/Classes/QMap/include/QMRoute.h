//
//  QMRoute.h
//  SOSOMap
//
//  Created by Alonzo on 13-9-17.
//  Copyright (c) 2013年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface QMRoute : NSObject


/**当前道路名称**/
@property(nonatomic, strong) NSString *currentRoadName;
/**
 *  下一个道路的名称
 */
@property(nonatomic, strong) NSString *nextRoadName;
/**
 *  到下一个转向的距离
 */
@property(nonatomic, strong) NSString *distance;

/**
 *  总的剩余距离
 */
@property(nonatomic, strong) NSString *totalDistanceLeft;
/**
 *  总的剩余时间
 */
@property(nonatomic, strong) NSString *timeLeft;
/**
 *路口信息
 *请参考附件中提供的图片和图片对应表
 **/
@property(nonatomic, strong) NSString* intersectionImageName;

/**
 *  总的剩余距离,单位米
 */
@property(nonatomic, assign) int totalDistanceLeftMeters;

@end
