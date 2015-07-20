/* AppController */

#import <Cocoa/Cocoa.h>
#import "HelpWindowController.h"
#import "VolumeView.h"
#import "VolumeViewController.h"
#include "AudioDeviceList.h"


@interface AppController : NSObject
{
	NSStatusItem	*mSbItem;
	NSMenu			*mMenu;
	NSMenuItem		*m2chMenu;
	NSMenuItem		*m64chMenu;
	NSMenu			*m2chBuffer;
	NSMenu			*m64chBuffer;

	BOOL			menuItemVisible;
    int             m2StartIndex;   //Menu Index of "None"
	int				m64StartIndex;

	NSMenuItem		*mCur2chDevice;
	NSMenuItem		*mCur64chDevice;
	NSMenuItem		*mCur2chBufferSize;
	NSMenuItem		*mCur64chBufferSize;

	//NSMenuItem		*mSuspended2chDevice;
	//NSMenuItem		*mSuspended64chDevice;

    AudioDeviceID   mSuspended2chDeviceID;
    AudioDeviceID   mSuspended64chDeviceID;

	AudioDeviceID				mSoundflower2Device;
	AudioDeviceID				mSoundflower64Device;

	AudioDeviceList *			mOutputDeviceList;

	UInt32 mNchnls2;
	UInt32 mNchnls64;

	AudioDeviceID mMenuID2[64];
	AudioDeviceID mMenuID64[64];

	IBOutlet HelpWindowController *mAboutController;
    //IBOutlet VolumeView *mVolumeView;
    id mVolumeViewController2ch;
    id mVolumeViewController64ch;
}

- (IBAction)suspend;
- (IBAction)resume;

- (IBAction)srChanged2ch;
- (IBAction)srChanged64ch;
- (IBAction)srChanged2chOutput;
- (IBAction)srChanged64chOutput;
- (IBAction)checkNchnls;
- (IBAction)volChanged2ch;

- (IBAction)refreshDevices;

- (IBAction)outputDeviceSelected:(id)sender;
- (IBAction)bufferSizeChanged2ch:(id)sender;
- (IBAction)bufferSizeChanged64ch:(id)sender;
- (IBAction)cloningChanged:(id)sender; //iSchemy
- (IBAction)cloningChanged:(id)sender cloneChannels:(bool)clone; //here too
- (IBAction)routingChanged2ch:(id)sender;
- (IBAction)routingChanged64ch:(id)sender;

- (void)buildRoutingMenu:(BOOL)is2ch;
- (void)buildDeviceList;
- (void)buildMenu;

- (void)InstallListeners;
- (void)RemoveListeners;

- (void)readGlobalPrefs;
- (void)writeGlobalPrefs;

- (void)readDevicePrefs:(BOOL)is2ch;
- (void)writeDevicePrefs:(BOOL)is2ch;

//- (IBAction)inputLoadChanged:(id)sender;
//- (IBAction)outputLoadChanged:(id)sender;
//- (IBAction)extraLatencyChanged:(id)sender;
//- (IBAction)toggleThru:(id)sender;
//- (IBAction)inputDeviceSelected:(id)sender;
//- (IBAction)inputSourceSelected:(id)sender;
//- (IBAction)outputSourceSelected:(id)sender;
//- (void)updateActualLatency:(NSTimer *)timer;

@end
