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


@property (strong, nonatomic) IBOutlet UIScrollView *scrollView;









//Birth


//6 Weeks




//10 Weeks



//14 Weeks



//6 - 12 Months



//15 - 18 Months



//2 - 5 Years


//9 - 13 Years



@end
