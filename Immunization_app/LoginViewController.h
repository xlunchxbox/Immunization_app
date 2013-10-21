//
//  ViewController.h
//  Immunization_app
//
//  Created by Christopher Cruz on 10/17/13.
//  Copyright (c) 2013 Team7. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LoginViewController : UIViewController
@property (weak, nonatomic) IBOutlet UITextField *username;
@property (weak, nonatomic) IBOutlet UITextField *password;


- (IBAction)loginBtn:(id)sender;
@end
