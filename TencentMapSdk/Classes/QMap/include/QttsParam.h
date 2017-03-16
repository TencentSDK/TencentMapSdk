//
//  QttsParam.h
//  QMapKit
//
//  Created by weizhengli on 2016.10.10.
//  Copyright 2016 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface QttsParam : NSObject


/**
 播报的字符串内容
 */
@property(strong)NSString* ttsString;

/**
 声音文件群路径
 */
@property(strong)NSString* filePath;

/**
 优先级，越小越高。暂时无用，保留
 */
@property(assign)int priority;

/**
 声音文件类型，目前只有叮一声。暂时无用，保留
 */
@property(assign)int messageType; 
+ (QttsParam*)ttsParamWithString:(NSString*)ttsString;
+ (QttsParam*)ttsParamWithString:(NSString*)ttsString Priority:(int)priority Type:(int)messageType;

@end
