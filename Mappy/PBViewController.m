//
//  PBViewController.m
//  Mappy
//
//  Created by Peter Barrett on 01/04/2014.
//  Copyright (c) 2014 Peter Barrett. All rights reserved.
//

#import "PBViewController.h"

@interface PBViewController ()
@property (nonatomic, strong) RFduino *rfduino;
@property (nonatomic, strong) RFduinoManager *manager;
@end

@implementation PBViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [self.rfduino setDelegate:self];
    self.manager = [RFduinoManager sharedRFduinoManager];
    [self.manager setDelegate:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)didConnectRFduino:(RFduino *)rfduino{
    NSLog(@"Device Name: %@",rfduino.name);
    
}

-(void)didDisconnectRFduino:(RFduino *)rfduino{
   
}

-(void)didUpdateDiscoveredRFduino:(RFduino *)rfduino{
}

-(void)didDiscoverRFduino:(RFduino *)rfduino{
    self.rfduino = rfduino;
    [self.rfduino setDelegate:self];

    [self.manager connectRFduino:self.rfduino];
}

-(void)didReceive:(NSData *)data{
   
    float d = dataFloat(data);
     NSLog(@"distance %f",d);
}



@end
