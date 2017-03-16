//
//  RouteSearchParser.h
//  QQMap
//
//  Created by Nopwang on 5/6/11.
//  Copyright 2011 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RouteResult.h"

typedef enum RouteResultErrorType_
{
    ERROR_TYPE_HAS_RESULT = 0,
    ERROR_TYPE_NO_RESULT = -1,
    ERROR_TYPE_FROM_AND_TO_IDENTICAL = 1,
    ERROR_TYPE_JCE_ERROR, //jce解析失败
    ERROR_TYPE_BOUND_RESULT_EMPTY,//围栏数据为空
    ERROR_TYPE_ROUTE_RESULT_EMPTY,//路线数据为空
    ERROR_TYPE_RET_ERROR,//错误码不为0
    ERROR_TYPE_TYPE_ERROR,//路线类型不是44也不是94
    ERROR_TYPE_DATA_EMPTY,//后台返回的回包为空
} RouteResultErrorType;


@interface RouteSearchParser : NSObject {

}

/*
 * @brief 带错误输出的路线解析方法
 *
 * @param resp JCE封装的路线二进制数据
 *
 * @param error 解析错误信息
 *
 * @return 返回解析后的路线对象
 */
- (RouteResult *)parseRouteWithData:(NSData*)resp error:(NSError **)error;

@end
