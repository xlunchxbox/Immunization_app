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


//LABEL ANCHORS
@property (weak, nonatomic) IBOutlet UILabel *birthTitle;
@property (weak, nonatomic) IBOutlet UILabel *sixWeekTitle;
@property (weak, nonatomic) IBOutlet UILabel *tenWeekTitle;
@property (weak, nonatomic) IBOutlet UILabel *fourtenWeekTitle;
@property (weak, nonatomic) IBOutlet UILabel *sixTwelveWeekTitle;
@property (weak, nonatomic) IBOutlet UILabel *fifteenEighteenMonthTitle;
@property (weak, nonatomic) IBOutlet UILabel *twoFiveYearTitle;
@property (weak, nonatomic) IBOutlet UILabel *nineThirteenTitle;






//Birth
@property (weak, nonatomic) IBOutlet UITextField *birthBcgDate;
@property (weak, nonatomic) IBOutlet UITextField *birthBcgAdministered;
@property (weak, nonatomic) IBOutlet UITextField *birthBcgHospital;
@property (weak, nonatomic) IBOutlet UITextField *birthBcgNext;

@property (weak, nonatomic) IBOutlet UITextField *birthHepDate;
@property (weak, nonatomic) IBOutlet UITextField *birthHepAdministered;
@property (weak, nonatomic) IBOutlet UITextField *birthHepHospital;
@property (weak, nonatomic) IBOutlet UITextField *birthHepNext;

@property (weak, nonatomic) IBOutlet UITextField *birthOpvDate;
@property (weak, nonatomic) IBOutlet UITextField *birthOpvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *birthOpvHospital;
@property (weak, nonatomic) IBOutlet UITextField *birthOpvNext;


//6 Weeks
@property (weak, nonatomic) IBOutlet UITextField *sixPcvDate;
@property (weak, nonatomic) IBOutlet UITextField *sixPcvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixPcvHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixPcvNext;

@property (weak, nonatomic) IBOutlet UITextField *sixHepDate;
@property (weak, nonatomic) IBOutlet UITextField *sixHepAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixHepHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixHepNext;

@property (weak, nonatomic) IBOutlet UITextField *sixOpvDate;
@property (weak, nonatomic) IBOutlet UITextField *sixOpvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixOpvHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixOpvNext;

@property (weak, nonatomic) IBOutlet UITextField *sixRvDate;
@property (weak, nonatomic) IBOutlet UITextField *sixRvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixRvHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixRvNext;

@property (weak, nonatomic) IBOutlet UITextField *sixDtapDate;
@property (weak, nonatomic) IBOutlet UITextField *sixDtapAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixDtapHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixDtapNext;


//10 Weeks
@property (weak, nonatomic) IBOutlet UITextField *tenPcvDate;
@property (weak, nonatomic) IBOutlet UITextField *tenPcvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *tenPcvHospital;
@property (weak, nonatomic) IBOutlet UITextField *tenPcvNext;

@property (weak, nonatomic) IBOutlet UITextField *tenOpvDate;
@property (weak, nonatomic) IBOutlet UITextField *tenOpvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *tenOpvHospital;
@property (weak, nonatomic) IBOutlet UITextField *tenOpvNext;

@property (weak, nonatomic) IBOutlet UITextField *tenRvDate;
@property (weak, nonatomic) IBOutlet UITextField *tenRvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *tenRvHospital;
@property (weak, nonatomic) IBOutlet UITextField *tenRvNext;

@property (weak, nonatomic) IBOutlet UITextField *tenDtapDate;
@property (weak, nonatomic) IBOutlet UITextField *tenDtapAdministered;
@property (weak, nonatomic) IBOutlet UITextField *tenDtapHospital;
@property (weak, nonatomic) IBOutlet UITextField *tenDtapNext;

@property (weak, nonatomic) IBOutlet UITextField *tenHibDate;
@property (weak, nonatomic) IBOutlet UITextField *tenHibAdministered;
@property (weak, nonatomic) IBOutlet UITextField *tenHibHospital;
@property (weak, nonatomic) IBOutlet UITextField *tenHibNext;


//14 Weeks
@property (weak, nonatomic) IBOutlet UITextField *fourteenPcvDate;
@property (weak, nonatomic) IBOutlet UITextField *fourteenPcvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fourteenPcvHospital;
@property (weak, nonatomic) IBOutlet UITextField *fourteenPcvNext;

@property (weak, nonatomic) IBOutlet UITextField *fourteenHepDate;
@property (weak, nonatomic) IBOutlet UITextField *fourteenHepAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fourteenHepHospital;
@property (weak, nonatomic) IBOutlet UITextField *fourteenHepNext;

@property (weak, nonatomic) IBOutlet UITextField *fourteenOpvDate;
@property (weak, nonatomic) IBOutlet UITextField *fourteenOpvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fourteenOpvHospital;
@property (weak, nonatomic) IBOutlet UITextField *fourteenOpvNext;

@property (weak, nonatomic) IBOutlet UITextField *fourteenRvDate;
@property (weak, nonatomic) IBOutlet UITextField *fourteenRvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fourteenRvHospital;
@property (weak, nonatomic) IBOutlet UITextField *fourteenRvNext;

@property (weak, nonatomic) IBOutlet UITextField *fourteenDtapDate;
@property (weak, nonatomic) IBOutlet UITextField *fourteenDtapAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fourteenDtapHospital;
@property (weak, nonatomic) IBOutlet UITextField *fourteenDtapNext;

@property (weak, nonatomic) IBOutlet UITextField *fourteenHibDate;
@property (weak, nonatomic) IBOutlet UITextField *fourteenHibAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fourteenHibHospital;
@property (weak, nonatomic) IBOutlet UITextField *fourteenHibNext;



//6 - 12 Months
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveInfluenzaDate;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveInfluenzaAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveInfluenzaHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveInfluenzaNext;

@property (weak, nonatomic) IBOutlet UITextField *sixTwelvePcvDate;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelvePcvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelvePcvHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelvePcvNext;

@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHepDate;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHepAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHepHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHepNext;

@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHibDate;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHibAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHibHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHibNext;

@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHepADate;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHepAAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHepAHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveHepANext;

@property (weak, nonatomic) IBOutlet UITextField *sixTwelveMmrDate;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveMmrAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveMmrHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveMmrNext;

@property (weak, nonatomic) IBOutlet UITextField *sixTwelveVaricellaDate;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveVaricellaAdministered;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveVaricellaHospital;
@property (weak, nonatomic) IBOutlet UITextField *sixTwelveVaricellaNext;



//15 - 18 Months
@property (weak, nonatomic) IBOutlet UITextField *fifteenHibDate;
@property (weak, nonatomic) IBOutlet UITextField *fifteenHibAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fifteenHibHospital;
@property (weak, nonatomic) IBOutlet UITextField *fifteenHibNext;

@property (weak, nonatomic) IBOutlet UITextField *fifteenHepDate;
@property (weak, nonatomic) IBOutlet UITextField *fifteenHepAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fifteenHepHospital;
@property (weak, nonatomic) IBOutlet UITextField *fifteenHepNext;

@property (weak, nonatomic) IBOutlet UITextField *fifteenMmrDate;
@property (weak, nonatomic) IBOutlet UITextField *fifteenMmrAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fifteenMmrHospital;
@property (weak, nonatomic) IBOutlet UITextField *fifteenMmrNext;

@property (weak, nonatomic) IBOutlet UITextField *fifteenDtapDate;
@property (weak, nonatomic) IBOutlet UITextField *fifteenDtapAdministered;
@property (weak, nonatomic) IBOutlet UITextField *fifteenDtapHospital;
@property (weak, nonatomic) IBOutlet UITextField *fifteenDtapNext;



//2 - 5 Years
@property (weak, nonatomic) IBOutlet UITextField *twoDtapDate;
@property (weak, nonatomic) IBOutlet UITextField *twoDtapAdministered;
@property (weak, nonatomic) IBOutlet UITextField *twoDtapHospital;
@property (weak, nonatomic) IBOutlet UITextField *twoDtapNext;

@property (weak, nonatomic) IBOutlet UITextField *twoVaricellaDate;
@property (weak, nonatomic) IBOutlet UITextField *twoVaricellaAdministered;
@property (weak, nonatomic) IBOutlet UITextField *twoVaricellaHospital;
@property (weak, nonatomic) IBOutlet UITextField *twoVaricellaNext;


//9 - 13 Years
@property (weak, nonatomic) IBOutlet UITextField *nineDtapDate;
@property (weak, nonatomic) IBOutlet UITextField *nineDtapAdministered;
@property (weak, nonatomic) IBOutlet UITextField *nineDtapHospital;
@property (weak, nonatomic) IBOutlet UITextField *nineDtapNext;

@property (weak, nonatomic) IBOutlet UITextField *nineMcvDate;
@property (weak, nonatomic) IBOutlet UITextField *nineMcvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *nineMcvHospital;
@property (weak, nonatomic) IBOutlet UITextField *nineMcvNext;

@property (weak, nonatomic) IBOutlet UITextField *nineHpvDate;
@property (weak, nonatomic) IBOutlet UITextField *nineHpvAdministered;
@property (weak, nonatomic) IBOutlet UITextField *nineHpvHospital;
@property (weak, nonatomic) IBOutlet UITextField *nineHpvNext;
















@end
