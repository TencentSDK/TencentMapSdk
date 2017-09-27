/*
 ============================================================================
 Name           : QAnnotationView.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QAnnotationView declaration
 ============================================================================
 */

#import <UIKit/UIKit.h>
#import "QAnnotation.h"
/* edit by cleverzhang 2014-08-19*/
//#import "QMAnnotationView.h"

#define DRAW_TEXT_FLAG @"drawText:"

@class QMAnnotationView;
//end
/**
 *QAnnotationView:标注view
 *Author:ksnowlv
 **/
@interface QAnnotationView : UIView

/* edit by cleverzhang 2014-09-11*/
typedef enum:NSUInteger{
    /**指定图片与坐标点位置关系，CENTER_MODE指定坐标点中心对应Image中心，
     BOTTOM_MODE指定坐标点在Image底部中点，布局如指针等标识。**/
    KIMAGE_DRAW_MODE_NONE = 0, // 当设置的anchorPoint不符合时
    KIMAGE_BOTTOM_LEFT_MODE,
    KIMAGE_BOTTOM_CENTER_MODE,
    KIMAGE_BOTTOM_RIGHT_MODE,
    KIMAGE_MIDDLE_LEFT_MODE,
    KIMAGE_MIDDLE_CENTER_MODE,
    KIMAGE_MIDDLE_RIGHT_MODE,
    KIMAGE_TOP_LEFT_MODE,
    KIMAGE_TOP_CENTER_MODE,
    KIMAGE_TOP_RIGHT_MODE,
}ImageDrawMode;
//end

/**
 *初始化并返回一个annotation view
 *@param annotation 关联的annotation对象
 *@param reuseIdentifier 如果要重用view,传入一个字符串,否则设为nil,建议重用view
 *@return 初始化成功则返回annotation view,否则返回nil
 */
- (id)initWithAnnotation:(id <QAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier;

/**复用标志**/
@property (nonatomic, readonly) NSString *reuseIdentifier;

/**
 *当view从reuse队列里取出时被调用
 *默认不做任何事
 */
- (void)prepareForReuse;

/**关联的annotation**/
@property (nonatomic, strong) id <QAnnotation> annotation;
/**
 *下落动画
 */
@property(nonatomic) BOOL animatesDrop;
/**annotation view显示的图像名称,必须提供图片的扩展名**/
@property (nonatomic, strong) NSString *imageName;
/**annotation view显示的图像,如果设置了imageIcon,imageName 的设置
 将无效,如果先设置imageName,设置imageIcon将覆盖imageName的设置**/
@property(nonatomic,strong)UIImage* imageIcon;
/**annotation view显示选中的图像名称**/
@property (nonatomic, strong) NSString *selectedImageName;

/**
 * 快速设置锚点位置, 默认为KIMAGE_MIDDLE_CENTER_MODE
 */
@property (nonatomic,assign) ImageDrawMode mDrawMode;

/**
 * annotation image 的锚点。当ImageDrawMode 不能满足要求时可以设置此属性
 * 取值为(0~1),如果不设置,默认为(0.5,0.5),对应于KIMAGE_MIDDLE_CENTER_MODE
 */
@property(nonatomic,assign)CGPoint anchorPoint;

/**
 * 中心点的偏移量，设置的结果会与anchorPoint叠加
 * 如：纹理的中心点为 (imageSize.width * anchorPoint.x + centerOffset.x, imageSize.height * anchorPoint.y + centerOffset.y)
 */
@property(nonatomic, assign)CGPoint centerOffset;

/**annotation显示优先级,优先级最高是1，值越大优先级越低，默认0则不做避让处理**/
@property(nonatomic, assign) NSInteger dispLevel;//display Priority

/**annotation的气泡是否翻转**/
@property(nonatomic, assign, readonly) BOOL calloutViewIsUnder;
/**
 * 气泡是否翻转, 默认是NO，禁止气泡翻转
 */
@property(nonatomic, assign) BOOL calloutViewCanUnder;

/**
 *默认情况下, 弹出的气泡位于view正中上方，可以设置calloutOffset改变view的位置，
 *正的偏移使view朝右下方移动，负的朝左上方，单位是像素
 ***/
@property (nonatomic) CGPoint calloutOffset;

/**默认为YES,当为NO时view忽略触摸事件**/
@property (nonatomic, getter=isEnabled) BOOL enabled;

/**默认为NO,这个属性会自动被设置或重置.**/
@property (nonatomic, getter=isHighlighted) BOOL highlighted;

/**默认为NO,当view被点中时被设为YES,用户不要直接设置这个属性.**/
@property (nonatomic, getter=isSelected) BOOL selected;

/**
 * 当手势点击时是否动画的方式弹出弹出calloutView, 默认为YES
 */
@property(nonatomic, assign)BOOL showCalloutAnimatedWhenTapped;

/**
 *设定view的选中状态
 *该方法被QMapView调用
 *@param selected 如果view需要显示为选中状态，该值为YES
 *@param animated 如果需要动画效果，该值为YES
 */
- (void)setSelected:(BOOL)selected animated:(BOOL)animated;


- (void)setCalloutViewIsUnder:(BOOL)isUnder;

/**当为YES时，view被选中时会弹出气泡，annotation必须实现了title这个方法,如果title为空，则会置为NO**/
@property (nonatomic) BOOL canShowCallout;
/**当为YES时，annotationView的callout在显示时自动滚动到可视范围内，如果为NO,则不滚动, 默认位YES**/
@property(nonatomic,assign)BOOL canCalloutScrollToVisible;
/**显示在气泡左侧的view**/
@property (strong, nonatomic) UIView *leftCalloutAccessoryView;

/**显示在气泡右侧的view**/
@property (strong, nonatomic) UIView *rightCalloutAccessoryView;
/****/
@property(nonatomic, assign)CGFloat angle;
@property(nonatomic, assign)CGFloat alpha;
/*文字避让*/
@property(nonatomic, assign)BOOL avoidAnnotation;
@end

