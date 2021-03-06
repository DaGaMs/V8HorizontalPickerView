//
//  V8HorizontalPickerView.h
//
//  Created by Shawn Veader on 9/17/10.
//  Copyright 2010 V8 Labs, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "V8HorizontalPickerViewProtocol.h"

// position of indicator view, if shown
typedef enum {
	V8HorizontalPickerIndicatorBottom = 0,
	V8HorizontalPickerIndicatorTop	
} V8HorizontalPickerIndicatorPosition;


@interface V8HorizontalPickerView : UIView <UIScrollViewDelegate> {
	UIScrollView *_scrollView;

	// collection of widths of each element.
	NSMutableArray *elementWidths;

	// what font to use for the element labels?
	UIFont *elementFont;

	// color of labels used in picker
	UIColor *textColor;
	UIColor *selectedTextColor; // color of current selected element
	
	NSInteger numberOfElements;
	NSInteger elementPadding;
	NSInteger currentSelectedIndex;
	V8HorizontalPickerIndicatorPosition indicatorPosition;

	// the point, defaults to center of view, where the selected element sits
	CGPoint selectionPoint;
	UIView *selectionIndicatorView;
	
	// views to display on edges of picker (eg: gradients, etc)
	UIView *leftEdgeView;
	UIView *rightEdgeView;

	// views for left and right of scrolling area
	UIView *leftScrollEdgeView;
	UIView *rightScrollEdgeView;

	// padding for left/right scroll edge views
	CGFloat scrollEdgeViewPadding;

	// state keepers
	BOOL dataHasBeenLoaded;
	BOOL scrollSizeHasBeenSet;

	// keep track of which elements are visible for tiling
	int firstVisibleElement;
	int lastVisibleElement;
}

@property (nonatomic, weak) id <V8HorizontalPickerViewDataSource> dataSource;
@property (nonatomic, weak) id <V8HorizontalPickerViewDelegate> delegate;
@property (nonatomic, readonly) NSInteger numberOfElements;
@property (nonatomic, readonly) NSInteger currentSelectedIndex;
@property (nonatomic, strong) UIFont *elementFont;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *selectedTextColor;
@property (nonatomic, assign) CGPoint selectionPoint;
@property (nonatomic, strong) UIView *selectionIndicatorView;
@property (nonatomic, assign) V8HorizontalPickerIndicatorPosition indicatorPosition;
@property (nonatomic, strong) UIView *leftEdgeView;
@property (nonatomic, strong) UIView *rightEdgeView;
@property (nonatomic, strong) UIView *leftScrollEdgeView;
@property (nonatomic, strong) UIView *rightScrollEdgeView;
@property (nonatomic, assign) CGFloat scrollEdgeViewPadding;



- (void)reloadData;
- (void)scrollToElement:(NSInteger)index animated:(BOOL)animate;

@end

// sub-class of UILabel that knows how to change it's state
@interface V8HorizontalPickerLabel : UILabel <V8HorizontalPickerElementState> {
	BOOL selectedElement;
	UIColor *selectedStateColor;
	UIColor *normalStateColor;
}

@property (nonatomic, assign) BOOL selectedElement;
@property (nonatomic, retain) UIColor *selectedStateColor;
@property (nonatomic, retain) UIColor *normalStateColor;

@end