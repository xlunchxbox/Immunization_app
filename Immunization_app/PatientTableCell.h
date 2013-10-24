//
//  PatientTableCell.h
//  Immunization_app
//
//  Created by Roberto Chupin on 10/23/13.
//  Copyright (c) 2013 Team7. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PatientTableCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *firstName;
@property (weak, nonatomic) IBOutlet UILabel *lastName;

@property (weak, nonatomic) IBOutlet UILabel *birthday;

@end
