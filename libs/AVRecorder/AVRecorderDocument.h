/*
     File: AVRecorderDocument.h
 Abstract: n/a
  Version: 2.1
 
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
 Inc. ("Apple") in consideration of your agreement to the following
 terms, and your use, installation, modification or redistribution of
 this Apple software constitutes acceptance of these terms.  If you do
 not agree with these terms, please do not use, install, modify or
 redistribute this Apple software.
 
 In consideration of your agreement to abide by the following terms, and
 subject to these terms, Apple grants you a personal, non-exclusive
 license, under Apple's copyrights in this original Apple software (the
 "Apple Software"), to use, reproduce, modify and redistribute the Apple
 Software, with or without modifications, in source and/or binary forms;
 provided that if you redistribute the Apple Software in its entirety and
 without modifications, you must retain this notice and the following
 text and disclaimers in all such redistributions of the Apple Software.
 Neither the name, trademarks, service marks or logos of Apple Inc. may
 be used to endorse or promote products derived from the Apple Software
 without specific prior written permission from Apple.  Except as
 expressly stated in this notice, no other rights or licenses, express or
 implied, are granted by Apple herein, including but not limited to any
 patent rights that may be infringed by your derivative works or by other
 works in which the Apple Software may be incorporated.
 
 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
 
 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 
 Copyright (C) 2012 Apple Inc. All Rights Reserved.
 
 */

 

#import <Cocoa/Cocoa.h>
#import <AVFoundation/AVFoundation.h>
@class AVCaptureVideoPreviewLayer;
@class AVCaptureSession;
@class AVCaptureDeviceInput;
@class AVCaptureMovieFileOutput;
@class AVCaptureAudioPreviewOutput;
@class AVCaptureConnection;
@class AVCaptureDevice;
@class AVCaptureDeviceFormat;
@class AVFrameRateRange;
@class AVCaptureStillImageOutput;

@interface AVRecorderDocument : NSDocument
{
@private
	NSView						*previewView;
	
	NSLevelIndicator			*audioLevelMeter;
	AVCaptureVideoPreviewLayer	*previewLayer;
	AVCaptureSession			*session;
	AVCaptureDeviceInput		*videoDeviceInput;
	AVCaptureDeviceInput		*audioDeviceInput;
	AVCaptureMovieFileOutput	*movieFileOutput;
	AVCaptureAudioPreviewOutput	*audioPreviewOutput;
	
	NSArray						*videoDevices;
	NSArray						*audioDevices;
	
	NSTimer						*audioLevelTimer;
	
	NSArray						*observers;
    
    NSString                    *outputPath;
    
    
    //AVCaptureFileOutputDelegate   *fileOutputDelegate;
    //AVCaptureFileOutputRecordingDelegate *recordingDelegate;
}

#pragma mark Device Selection
- (void)refreshDevices;
- (void)setSelectedVideoDevice:(AVCaptureDevice *)selectedVideoDevice;
- (void)setSelectedAudioDevice:(AVCaptureDevice *)selectedAudioDevice;
@property (retain) NSArray *videoDevices;
@property (retain) NSArray *audioDevices;
@property (assign) AVCaptureDevice *selectedVideoDevice;
@property (assign) AVCaptureDevice *selectedAudioDevice;

#pragma mark - Device Properties
@property (assign) AVCaptureDeviceFormat *videoDeviceFormat;
@property (assign) AVCaptureDeviceFormat *audioDeviceFormat;
@property (assign) AVFrameRateRange *frameRateRange;
- (IBAction)lockVideoDeviceForConfiguration:(id)sender;

#pragma mark - Recording
@property (retain) AVCaptureSession *session;
@property (readonly) NSArray *availableSessionPresets;
@property (readonly) BOOL hasRecordingDevice;
@property (assign,getter=isRecording) BOOL recording;
@property (retain) NSString* outputPath;
@property (retain) AVCaptureVideoPreviewLayer	*previewLayer;

#pragma mark - Image
@property AVCaptureStillImageOutput *stillImageOutput;
- (void) captureNow: (NSString *) path;
- (void) saveImage: (CIImage *)image targetPath:(NSString *)path;

#pragma mark - Preview
@property (assign) NSView *previewView;
@property (assign) float previewVolume;
@property (assign) NSLevelIndicator *audioLevelMeter;

#pragma mark - Transport Controls
@property (readonly,getter=isPlaying) BOOL playing;
@property (readonly,getter=isRewinding) BOOL rewinding;
@property (readonly,getter=isFastForwarding) BOOL fastForwarding;


@property (nonatomic,assign) id<AVCaptureFileOutputDelegate,AVCaptureFileOutputRecordingDelegate>delegate;


@end
