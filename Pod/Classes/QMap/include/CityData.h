//
//  CityData.h
//  QQMap
//
//  Created by Jasonzhang on 6/29/11.
//  Copyright 2011 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum CityDataState_ {
    CityData_None,                      // No city data
    CityData_Available,                 // No city data in local, while available on server
    CityData_Downloading,               // Downloading city data from server
    CityData_Pause,                     // Pause downloading
    CityData_OK,                         // Data is ready for using
    
    CityData_Installing = 10,           // Is installing
    CityData_DownloadFail = 11,         // Fail to download
    CityData_InstallFail = 12,          // Fail to install
} CityDataState;


@interface CityData : NSObject <NSCoding> {
    int             ID_;                // e.g. 0
    int             version_;           // e.g. 1
    NSString*       name_;              // e.g. "怀化"
    NSString*       spelling_;          // e.g. "huaihua"
    NSString*       spellingForShort_;  // e.g. "hh"
    NSString*       areaID_;            // e.g. "0745"
    NSInteger             provinceID_;        // e.g. 0 (Beijing)
    
    CityDataState   curState_;          // e.g. CityData_Available
    NSInteger             totalSize_;         // e.g. 1024000000, in byte
    NSInteger             displaySize_;       // e.g. 650
    NSInteger             downloadedSize_;    // e.g. 512, in byte
    BOOL            isDataReadyForUse_; // YES when ready and updating, NO when no data or downloading
}


@property (nonatomic)   int ID;
@property (nonatomic)   int version;
@property (nonatomic, copy) NSString*   name;
@property (nonatomic, copy) NSString*   spelling;
@property (nonatomic, copy) NSString*   spellingForShort;
@property (nonatomic, copy) NSString*   areaID;
@property (nonatomic)   NSInteger provinceID;
@property (nonatomic, setter = setCurState:)   CityDataState   curState;
@property (nonatomic)   NSInteger totalSize;      //totalSize 可能会重置为0，需要显示数据包大小，请使用displaySzie
@property (nonatomic)   NSInteger displaySize;
@property (nonatomic)   NSInteger downloadedSize;
@property (nonatomic) double lastStateChangeTime;
@property (nonatomic)   BOOL isDataReadyForUse;
@property (nonatomic, copy) NSString* updateDate;
@property (nonatomic, copy) NSString* MD5;
@property(nonatomic, assign)BOOL isHasUpdateData;
@property(nonatomic,assign)BOOL isHasOfflineData;
@property (nonatomic, copy) NSString* provinceSpelling;
@end
