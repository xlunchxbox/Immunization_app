//
//  ViewController.m
//  Immunization_app
//
//  Created by Christopher Cruz on 10/17/13.
//  Copyright (c) 2013 Team7. All rights reserved.
//

#import "LoginViewController.h"
#import "AFNetworking.h"
@interface LoginViewController ()

@end



@implementation LoginViewController
static AFHTTPRequestOperationManager *manager;

@synthesize scrollView;
@synthesize username;
@synthesize password;
@synthesize activeField;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.password.delegate = self;
    self.username.delegate = self;
    
    [self registerForKeyboardNotifications];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


//=============
// Call this method somewhere in your view controller setup code.
- (void)registerForKeyboardNotifications
{
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWasShown:)
                                                 name:UIKeyboardDidShowNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillBeHidden:)
                                                 name:UIKeyboardWillHideNotification object:nil];
    
}

// Called when the UIKeyboardDidShowNotification is sent.
- (void)keyboardWasShown:(NSNotification*)aNotification
{
    NSDictionary* info = [aNotification userInfo];
    CGSize kbSize = [[info objectForKey:UIKeyboardFrameBeginUserInfoKey] CGRectValue].size;
    
    UIEdgeInsets contentInsets = UIEdgeInsetsMake(0.0, 0.0, kbSize.height, 0.0);
    scrollView.contentInset = contentInsets;
    scrollView.scrollIndicatorInsets = contentInsets;
    
    // If active text field is hidden by keyboard, scroll it so it's visible
    // Your application might not need or want this behavior.
    CGRect aRect = self.view.frame;
    aRect.size.height -= kbSize.height;
    if (!CGRectContainsPoint(aRect, activeField.frame.origin) ) {
        CGPoint scrollPoint = CGPointMake(0.0, activeField.frame.origin.y-kbSize.height);
        [scrollView setContentOffset:scrollPoint animated:YES];
        [scrollView setContentOffset:CGPointMake(0,activeField.center.y-200) animated:YES];
    }
}

// Called when the UIKeyboardWillHideNotification is sent
- (void)keyboardWillBeHidden:(NSNotification*)aNotification
{
    UIEdgeInsets contentInsets = UIEdgeInsetsZero;
    scrollView.contentInset = contentInsets;
    scrollView.scrollIndicatorInsets = contentInsets;
}
- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    activeField = textField;
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    activeField = nil;
}
//=============


- (IBAction)loginBtn:(id)sender {
    //NSURL *URL = [NSURL URLWithString:@"http://192.168.1.127:3000/login"]; //locally at James' House
    
    manager = [AFHTTPRequestOperationManager manager];
	NSDictionary *parameters = @{@"username": self.username.text, @"password": self.password.text};
	[manager POST:@"http://stark-beyond-9579.herokuapp.com/login"parameters:parameters success:^(AFHTTPRequestOperation *operation, id responseObject) {
		NSLog(@"JSON: %@", responseObject);
		if ([[responseObject valueForKey:@"status"] isEqualToString:@"success"]) {

		} else {
            [[[UIAlertView alloc] initWithTitle:@"Error A" message:nil delegate:self cancelButtonTitle:@"Dismiss" otherButtonTitles:nil] show];
        }
	} failure:^(AFHTTPRequestOperation *operation, NSError *error) {
		NSLog(@"Error: %@", error);
        [[[UIAlertView alloc] initWithTitle:@"Error B" message:nil delegate:self cancelButtonTitle:@"Dismiss" otherButtonTitles:nil] show];
	}];

}
@end
