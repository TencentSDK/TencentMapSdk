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
 *  到下一个转向的距离字符串
 */
@property(nonatomic, strong) NSString *distance;

/**
 *  到下一个转向的距离数值，单位米
 */
@property(nonatomic, assign) NSInteger distanceMeters;

/**
 *  总的剩余距离字符串
 */
@property(nonatomic, strong) NSString *totalDistanceLeft;

/**
 *  总的剩余距离数值，单位米
 */
@property(nonatomic, assign) int totalDistanceLeftMeters;

/**
 *  总的剩余时间字符串
 */
@property(nonatomic, strong) NSString *timeLeft;

/**
 *  总的剩余时间数值，单位秒
 */
@property(nonatomic, assign) NSInteger timeLeftSeconds;

/**
 *路口信息
 *请参考附件中提供的图片和图片对应表
 **/
@property(nonatomic, strong) NSString* intersectionImageName;



@end
