//
//  QOfflinData.h
//  
//
//  Created by Alonzo on 14-3-6.
//  Copyright (c) 2014年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CityData.h"

@protocol IDataReceiveNotification;
@protocol IViewNotification;
typedef enum _CityDataUpdateResult{
    CHECK_CITYDATA_AND_UPDATED=0,                      // 检查并更新了城市配置文件
    CHECK_CIYTDATA_WITHOUT_UPDATE,                 // 检查但是不需要更新
    CHECK_CITYDATA_WITH_NET_ERROR,               // 网络错误
} CityDataUpdateResult;


@protocol OffLineCityDelegate <NSObject>

- (void)onReceiveCity:(CityData*)city Size:(NSInteger)currentLength totalLength:(NSInteger)length;
- (void)cityDataIsReadyForUse:(CityData*)city;
- (void)notifyCheckCityDataUpdateResult:(CityDataUpdateResult)result;
- (void)onReceiveCity:(CityData*)city Error:(NSError*)error;
@end

@interface QOffLineData : NSObject

@property (atomic, weak) id<OffLineCityDelegate> delegate;

+ (QOffLineData *)defaultManager ;
/**
 *开始下载
 *
 */
- (void)startTask:(CityData *)city;
/**
 *暂停下载中的任务
 *
 */
- (void)pauseTask:(CityData *)city;
/**
 *取消下载中的任务，同时清理已经下载的数据，只处理下载中和暂停两种状态
 *
 */
- (void)cancelTask:(CityData *)city;
/**
 *删除下载，重置城市下载数据， 如果已经下载完毕，同时清理数据
 *调用之前需要先调用- (void)cancelTask:(CityData *)city接口，确保处于下载中或暂停的任务从任务栈中移除
 *
 */
- (BOOL)deleteCityData:(CityData *)city;

/**
 *根据区号返回CityData
 *
 */
- (CityData *) findCityByareaID:(NSString *)areaID;


/**
 *检查是否有新的离线数据,在应用启动时调用
 *
 */
-(void)checkCityDataUpdate;

/**
 *加载离线地图界面 *
 */
-(UIViewController*)getOfflineMapVC;

/**
 *保存下载数据状态，触发applicationDidEnterBackground时需要调用 *
 */
-(void)saveToarchive;
@end
