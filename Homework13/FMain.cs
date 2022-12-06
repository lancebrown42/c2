// ----------------------------------------------------------------------
// Name: <Your name>
// Class: SET-252 - C Programming #2 
// Abstract: Homework #13 - Recursion Part 2 - TrimAllFormTextBoxes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Imports
// ----------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using nsUtilities;


namespace Homework13_TrimAllFormTextboxes
{
    public partial class FMain : Form
    {
        // ----------------------------------------------------------------------
        // Name: FMain
        // Abstract: Constructro
        // ----------------------------------------------------------------------
        public FMain( )
        {
            try
            {
                InitializeComponent( );
            }
            catch ( Exception excError )
            {
                // Display error message
                CWriteLog.WriteLog( excError );
            }
        }


        // ----------------------------------------------------------------------
        // Name: btnShazam_Click
        // Abstract: Make it so!
        // ----------------------------------------------------------------------
        private void btnShazam_Click( object sender, EventArgs e )
        {
            try
            {
				TrimText(this.Controls);
            }
            catch ( Exception excError )
            {
                // Display error message
                CWriteLog.WriteLog( excError );
            }
        }

		private void TrimText(Control.ControlCollection ctrl)
		{
			try {
				GroupBox ctrlGroup = null;
				for (int i = 0; i < ctrl.Count; i++) {
					ctrl[i].Text = ctrl[i].Text.Trim();
					if(ctrl[i].GetType() == typeof(System.Windows.Forms.GroupBox)) {
						ctrlGroup = (GroupBox) ctrl[i];
						TrimText(ctrlGroup.Controls);
					}
				}
			}
			catch (Exception excError) {
				// Display error message
				CWriteLog.WriteLog(excError);
			}
		}
    }
}
