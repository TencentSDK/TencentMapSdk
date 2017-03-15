//
//  QConnectionWrapper.h
//  QMapKit
//
//  Created by weizhengli on 2016.11.24.
//  Copyright 2016 Tencent. All rights reserved.
//

@protocol QMConnectionWrapperDelegate;


/**
 业务类型的定义分类

 - kReqType_other: 默认的请求，不推荐使用
 - kReqType_sctx: 司乘同显
 - kReqType_yzx: 一致性
 - kReqType_passengerRainbow: 乘客端蚯蚓更新
 */
typedef NS_ENUM(NSInteger, ReqType) {
    kReqType_other = 0,
    kReqType_sctx,
    kReqType_yzx,
    kReqType_passengerRainbow,
};


/**
 这个类是SDK内的网络封装类，只针对拆分司乘同显后 司乘同显，一致性，乘客端蚯蚓更新 这3个网络特殊 使用，
 其他模块不应该使用
 */
@interface QMConnectionWrapper : NSObject


///////////////输入数据//////////////////

/**
 网络请求的server地址
 */
@property(nonatomic, strong, readonly) NSString *urlString;

/**
 post网络请求的数据
 */
@property(nonatomic, strong, readonly) NSData *postData;

/**
 请求回调代理
 */
@property(nonatomic, weak, readonly) id<QMConnectionWrapperDelegate> delegate;

/**
 请求业务类型
 */
@property(nonatomic, assign) ReqType reqType;

///////////////输出数据//////////////////

/**
 网络返回的response数据

 @return 网络返回的response数据
 */
- (NSData*)responseData;

/**
 开始网络请求

 @param url 网络地址
 @param postData 请求数据
 @param type 业务类型
 @param delegate 回调代理
 */
- (void)startConnection:(NSString*)url PostData:(NSData*)postData Type:(ReqType)type Delegate:(id<QMConnectionWrapperDelegate>)delegate;

/**
 *  取消当前的请求
 */
-(void)cancelReq;

/**
 是否正在请求网络中
 
 @return 是否正在请求网络中
 */
- (BOOL)isRequesting;

@end


/**
 网络回调代理接口
 */
@protocol QMConnectionWrapperDelegate <NSObject>

/**
 网络成功回调

 @param connectionItem 请求时的实例
 */
- (void)connectionItemDidFinish:(QMConnectionWrapper *)connectionItem;

/**
 网络失败回调

 @param connectionItem connectionItem 请求时的实例
 @param error 失败信息
 */
- (void)connectionItem:(QMConnectionWrapper *)connectionItem didFailWithError:(NSError *)error;
@end
