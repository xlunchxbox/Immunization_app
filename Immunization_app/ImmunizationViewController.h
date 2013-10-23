//
//  ImmunizationViewController.h
//  Immunization_app
//
//  Created by Christopher Cruz on 10/21/13.
//  Copyright (c) 2013 Team7. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ImmunizationViewController : UIViewController
- (IBAction)birthBtn:(id)sender;
- (IBAction)sixWeeksBtn:(id)sender;
- (IBAction)tenWeeksBtn:(id)sender;
- (IBAction)fourteenWeeksBtn:(id)sender;
- (IBAction)nineToTwelveMonthsBtn:(id)sender;
- (IBAction)fifteenToEighteenMonthsBtn:(id)sender;
- (IBAction)twoToFiveYearsBtn:(id)sender;
- (IBAction)nineToThirteenYearsbtn:(id)sender;
- (IBAction)medicalHistoryBtn:(id)sender;
- (IBAction)uploadPhotoBtn:(id)sender;
- (IBAction)logoutBtn:(id)sender;


//Birth
@property (weak, nonatomic) IBOutlet UITextField *birthBcgDa;

//6 Weeks
@property (weak, nonatomic) IBOutlet UITextField *sixWeeksPcvDa;



//10 Weeks
@property (weak, nonatomic) IBOutlet UITextField *tenWeeksPcvDa;


//14 Weeks
@property (weak, nonatomic) IBOutlet UITextField *fourteenWeeksPcvDa;


//6 - 12 Months
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveInfluenzaDa;


//15 - 18 Months
@property (weak, nonatomic) IBOutlet UITextField *fifteenEighteenHibDa;


//2 - 5 Years
@property (weak, nonatomic) IBOutlet UITextField *twoFiveDtapDa;

//9 - 13 Years
@property (weak, nonatomic) IBOutlet UITextField *nineThirteenDtapDa;


@end
