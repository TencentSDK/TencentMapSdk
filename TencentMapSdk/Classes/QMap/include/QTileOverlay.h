//
//  QTileOverlay.h
//  QMapKit
//
//  Created by tabsong on 15/8/10.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QGeometry.h"

typedef struct {
    NSInteger x;
    NSInteger y;
    NSInteger z;
} QTileOverlayPath;

@interface QTileOverlay : NSObject

/*!
 *  @brief  最小zoom级别.
 */
@property (nonatomic, assign) NSInteger minimumZ;

/*!
 *  @brief  最大zoom级别.
 */
@property (nonatomic, assign) NSInteger maximumZ;

/*!
 *  @brief  水平范围.
 */
@property (nonatomic, assign) QMapRect boundingMapRect;

/*!
 *  @brief  tile当前是否过期. 重载 - (void)loadTileAtPath:(QTileOverlayPath)path result:(void (^)(UIImage *tileImage, NSError *error))result; 时, 
 *          异步加载数据前调用该API, 若返回NO, 则无需加载数据. 没有任何地方用到。
 *
 *  @param path     tile 的索引
 *  @param result   tile当前是否过期
 */
//- (BOOL)tileAtPathIsExpired:(QTileOverlayPath)path;

@end

@interface QTileOverlay (CustomLoading)

/*!
 *  @brief  加载tile数据
 *
 *  @param path     tile 的索引
 *  @param result   数据准备好后, 调用该block
 */
- (void)loadTileAtPath:(QTileOverlayPath)path result:(void (^)(UIImage *tileImage, NSError *error))result;

@end
