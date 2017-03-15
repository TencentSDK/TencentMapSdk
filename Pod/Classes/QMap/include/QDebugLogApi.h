//
//  QDebugLogApi.h
//  QDebugLogApi
//
//  Created by weizhengli on 16-5-11.
//  Copyright (c) 2016年 tencent. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef enum {
    QLogTypeInfo = 0,
    QLogTypeDebug = 1,
    QLogTypeError = 2,
} QLogType;

typedef enum {
    QSdkModuleTag_SDK = 0,
    QSdkModuleTag_sctx = 1,
    QSdkModuleTag_yzx = 2,
    QSdkModuleTag_smooth = 3,
    QSdkModuleTag_navi = 4,
    QSdkModuleTag_mapview = 5,
    QSdkModuleTag_qmlog = 6,
    QSdkModuleTag_location = 7,
    QSdkModuleTag_refresh = 8,  //司乘同显下的擦除后视野刷新
    QSdkModuleTag_mapProxy = 9,    // 地图封装层
    QSdkModuleTag_naviProxy = 10,    //导航封装层，包括司乘同显
} QSdkModuleTag;



@interface QDebugLogApi : NSObject
{
}

/**
 *  设置是否将日志写文件
 *
 *  @param isDebugToFile 是否写入debug日志
 *  @param isErrorFile   是否写入error日志
 */
+ (void)setWriteDebugLogToFile:(BOOL)isDebugToFile ErrorLogToFile:(BOOL)isErrorFile;

/**
 *  设置日志的回调
 *
 *  @param debugCallback debug日志回调
 *  @param errorCallback error日志回调
 */
+ (void)setDebugLogCallback:(void (^)(NSString*szLog))debugCallback ErrorLogCallback:(void (^)(NSString*szLog))errorCallback;

/**
 *  设置Info级别的日志回调
 *
 *  @param callback info日志回调
 */
+ (void)setInfoLogCallback:(void (^)(NSString*szLog))callback;

/**
 *  设置日志屏蔽模块
 *
 *  @param array 屏蔽模块的数组
 */
+ (void)setSheldLogTag:(NSArray*)array;


@end 

