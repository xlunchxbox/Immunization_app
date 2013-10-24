//
//  ProfileViewController.m
//  Immunization_app
//
//  Created by Christopher Cruz on 10/21/13.
//  Copyright (c) 2013 Team7. All rights reserved.
//

#import "ProfileViewController.h"

@interface ProfileViewController ()

@end

@implementation ProfileViewController 

@synthesize firstName, lastName, dateOfBirth, gender,
            phoneNumber,streetAddress, city, state, zip, country, email;

@synthesize scrollView, activeField;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
    
    self.phoneNumber.delegate = self;
    self.streetAddress.delegate = self;
    self.city.delegate = self;
    self.state.delegate = self;
    self.zip.delegate = self;
    self.country.delegate = self;
    self.email.delegate = self;

    
    self.firstName.text = [self.patientArray valueForKey:@"firstName"];

    self.lastName.text = [self.patientArray valueForKey:@"lastName"];
    
    NSString* birthDay = [self.patientArray valueForKey:@"birthDay"];
    NSString* birthMonth = [self.patientArray  valueForKey:@"birthMonth"];
    NSString* birthYear = [self.patientArray valueForKey:@"birthYear"];
    self.dateOfBirth.text = [NSString stringWithFormat:@"%@/%@/%@",birthMonth, birthDay, birthYear ];

    self.gender.text = [self.patientArray valueForKey:@"gender"];
    
    
    
    self.phoneNumber.text = [self.patientArray valueForKey:@"contactPhone"];
    self.streetAddress.text = [self.patientArray valueForKey:@"contactStreetAddress"];
    self.city.text = [self.patientArray valueForKey:@"contactCity"];
    self.state.text = [self.patientArray valueForKey:@"contactState"];
    self.zip.text = [self.patientArray valueForKey:@"contactZip"];
    self.country.text = [self.patientArray valueForKey:@"contactCountry"];
    self.email.text = [self.patientArray valueForKey:@"contactEmail"];
    
    [self registerForKeyboardNotifications];
    [activeField resignFirstResponder];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


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
        [scrollView setContentOffset:CGPointMake(0,activeField.center.y-50) animated:YES];
    }
}

// Called when the UIKeyboardWillHideNotification is sent
- (void)keyboardWillBeHidden:(NSNotification*)aNotification
{
    UIEdgeInsets contentInsets = UIEdgeInsetsZero;
    scrollView.contentInset = contentInsets;
    scrollView.scrollIndicatorInsets = contentInsets;
}

-(BOOL)textFieldShouldReturn:(UITextField*)textField;
{
    // UITextField *first = self.activeField;
    NSInteger nextTag = textField.tag + 1;
    // Try to find next responder
    UIResponder* nextResponder = [textField.superview viewWithTag:nextTag];
    if (nextResponder) {
        // Found next responder, so set it.
        
        [nextResponder becomeFirstResponder];
      //  if(activeField == self.)
        [scrollView setContentOffset:CGPointMake(0,activeField.center.y-50) animated:YES];
        
    } else {
        // Not found, so remove keyboard.
        [textField resignFirstResponder];
    }
    return NO; // We do not want UITextField to insert line-breaks.
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





- (IBAction)updateInfoBtn:(id)sender {
}

- (IBAction)vaccinationBtn:(id)sender {
}

- (IBAction)medicalHistory:(id)sender {
}

- (IBAction)uploadPhotoBtn:(id)sender {
}

- (IBAction)logoutBtn:(id)sender {
}


- (IBAction)vaccination:(id)sender {
}

@end
