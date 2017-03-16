//
//  QHeatTileOverlay.h
//  QMapKit
//
//  Created by tabsong on 15/8/10.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#import "QTileOverlay.h"
#import "QHeatTileNodeProtocol.h"

@interface QHeatTileOverlay : QTileOverlay

/*!
 *  @brief  生成热力图overlay, 默认的衰变半径为26
 *
 *  @param heatTileNodes 热力图节点元素数组, 每个元素符合 QHeatTileNodeProtocol 协议
 *  @return heatTileOverlay
 */
- (instancetype)initWithHeatTileNodes:(NSArray *)heatTileNodes;

/*!
 *  @brief  生成热力图overlay
 *
 *  @param heatTileNodes 热力图节点元素数组, 每个元素符合 QHeatTileNodeProtocol 协议
 *  @param decayRadius 衰变半径, 超过30会影响效率, 参数若 <= 0, 会使用默认值26
 *  @return heatTileOverlay
 */
- (instancetype)initWithHeatTileNodes:(NSArray *)heatTileNodes decayRadius:(NSInteger)decayRadius;

/*!
 *  @brief  衰变半径
 */
@property (nonatomic, readonly) NSInteger decayRadius;

/**
 *  根据zoom级别处理node.value 数据. 默认为 YES.
 *  影响到 - (void)colorForValue:(CGFloat)value outRed:(CGFloat *)outRed outGreen:(CGFloat *)outGreen outBlue:(CGFloat *)outBlue outAlpha:(CGFloat *)outAlpha; 中的value参数.
 */
@property (nonatomic, assign) BOOL normalizeNodeValueAccordingZoom;

/*!
 *  @brief  更新热力图节点数据(全部更新)
 *
 *  @param heatTileNodes 热力图节点元素数组, 每个元素符合 QHeatTileNodeProtocol 协议
 */
- (void)updateHeatTileNodes:(NSArray *)heatTileNodes;

@end

// 子类可以重载来配置热力图色盘
@interface QHeatTileOverlay (CustomColorPalete)

/*!
 *  @brief  根据热度值生成颜色.
 *
 *  @param heatValue 热力值
 *  @param outRed    需要填充的red分量
 *  @param outGreen  需要填充的green分量
 *  @param outBlue   需要填充的blue分量
 *  @param outAlpha  需要填充的alpha分量
 */
- (void)colorForValue:(CGFloat)value outRed:(CGFloat *)outRed outGreen:(CGFloat *)outGreen outBlue:(CGFloat *)outBlue outAlpha:(CGFloat *)outAlpha;

@end
