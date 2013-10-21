//
//  MedicalHIstoryViewController.h
//  Immunization_app
//
//  Created by Christopher Cruz on 10/21/13.
//  Copyright (c) 2013 Team7. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MedicalHIstoryViewController : UIViewController
@property (weak, nonatomic) IBOutlet UILabel *bloodType;
@property (weak, nonatomic) IBOutlet UITextView *allergies;
@property (weak, nonatomic) IBOutlet UITextView *diseaseHistory;
@property (weak, nonatomic) IBOutlet UITextView *notes;

- (IBAction)vaccinationBtn:(id)sender;
- (IBAction)uploadPhotoBtn:(id)sender;
- (IBAction)logoutBtn:(id)sender;
@end
