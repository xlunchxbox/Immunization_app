//
//  SearchViewController.h
//  Immunization_app
//
//  Created by Christopher Cruz on 10/21/13.
//  Copyright (c) 2013 Team7. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SearchViewController : UIViewController <UITextFieldDelegate>
@property (strong, nonatomic) IBOutlet UITextField *firstName;
@property (strong, nonatomic) IBOutlet UITextField *lastName;
@property (strong, nonatomic) IBOutlet UITextField *month;
@property (strong, nonatomic) IBOutlet UITextField *day;
@property (strong, nonatomic) IBOutlet UITextField *year;
@property (strong, nonatomic) IBOutlet UITextField *userId;

@property (strong, nonatomic) IBOutlet UIScrollView *scrollView;
@property (strong, nonatomic) IBOutlet UITextField *activeField;




- (IBAction)searchBtn:(id)sender;
- (IBAction)logoutBtn:(id)sender;

@end
