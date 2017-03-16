//
//  QGlobalConfig.h
//  QGlobalConfig
//
//  Created by weizhengli on 16-6-15.
//  Copyright (c) 2016年 tencent. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef enum {
    kServerType_release = 0,    //上线环境
    kServerType_test = 1,       //测试环境使用，给测试同学
    kServerType_debug = 2,      //开发环境联调
} ServerType;


@interface QGlobalConfig : NSObject

/**
 *  是否要写入GPS数据，在debug情况下推荐设置为YES，默认为NO
 */
@property(assign, nonatomic)BOOL isWriteGPS;


/**
 *  使用司乘同显测试服务器地址,默认是上线环境
 */
@property(assign)ServerType serverType;

/**
 *  默认是否擦除路线,默认是YES
 */
@property(assign)BOOL isEraseNaviRoute;

/**
 *  写入服务端数据到本地文件,默认是NO
 */
@property(assign)BOOL isWriteServerData;


/**
 *  无路线无动画？，默认是NO，即无路线有动画的
 */
@property(assign)BOOL isNORouteNoAnimated;


@property (nonatomic, assign) BOOL isWriteGLLayerLog;


+ (QGlobalConfig *)defaultManager;

@end 

