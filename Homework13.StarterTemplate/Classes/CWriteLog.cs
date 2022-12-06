// -------------------------------------------------------------------------
// Name: Patrick Callahan
// Abstract: WriteLog - Log messages to disk
//
// Revision        Owner   Changes:
// 2013/04/07      P.C.    For Book
// 2013/10/09      P.C.    C# version
// -------------------------------------------------------------------------

// -------------------------------------------------------------------------
// Imports
// -------------------------------------------------------------------------
using System;
using System.IO;
using System.Windows.Forms;

// Must have "using nsUtilities" or change namespace here to match the rest of the project.
// Everything is static so you don't need to make an instance to call.
// Sample procedure usage:
//
//  private void DoSomething( )
//  {
//      try
//      {
//          // Your code here
//      }
//      catch ( Exception excError )
//      {
//          CWriteLog.WriteLog( excError );
//      }
//  }

namespace nsUtilities
{

    class CWriteLog
    {

        // -------------------------------------------------------------------------
        //  Constants
        // -------------------------------------------------------------------------
        // What log file should we use
        private const String strLOG_FILE_EXTENSION = ".Log";

        // -------------------------------------------------------------------------
        //  Properties
        // -------------------------------------------------------------------------
        private static String m_strOldLogFilePath = "";        // Name of the last log file opened
        private static FileStream m_fsLogFile = null;          // File handle of the last log file opened


        // -------------------------------------------------------------------------
        // Name: WriteLog
        // Abstract: Overload withd blnDisplay set to true
        // -------------------------------------------------------------------------
        public static void WriteLog( Exception excErrorToLog )
        {
            try
            {
                WriteLog( excErrorToLog.ToString( ), true );
            }
            catch( Exception excError )
            {
                // Display error message
                MessageBox.Show( "Error:\n" + excError.ToString( ), Application.ProductName,
                                MessageBoxButtons.OK, MessageBoxIcon.Warning );
            }
        }


        // -------------------------------------------------------------------------
        // Name: WriteLog
        // Abstract: Overload withd blnDisplay set to true
        // -------------------------------------------------------------------------
        public static void WriteLog( Exception excErrorToLog,
                                     Boolean blnDisplayWarning )
        {
            try
            {

                WriteLog( excErrorToLog.ToString( ), blnDisplayWarning );
            }
            catch( Exception excError )
            {
                // Display error message
                MessageBox.Show( "Error:\n" + excError.ToString( ), Application.ProductName,
                                MessageBoxButtons.OK, MessageBoxIcon.Warning );
            }
        }


        // -------------------------------------------------------------------------
        // Name: WriteLog
        // Abstract: Write a message to the error log.
        // -------------------------------------------------------------------------
        public static void WriteLog( String strMessageToLog )
        {
            try
            {
                WriteLog( strMessageToLog, true );
            }
            catch( Exception excError )
            {
                // Display error message
                MessageBox.Show( "Error:\n" + excError.ToString( ), Application.ProductName,
                                MessageBoxButtons.OK, MessageBoxIcon.Warning );
            }
        }


        // -------------------------------------------------------------------------
        // Name: WriteLog
        // Abstract: Write a message to the error log.
        // -------------------------------------------------------------------------
        public static void WriteLog( String strMessageToLog, 
                                     Boolean blnDisplayWarning )
        {
            try
            {
                FileStream fsLogFile = null;
                System.Text.UTF8Encoding encConvertToByteArray = new System.Text.UTF8Encoding( );

                // Warn the user?
                if( blnDisplayWarning == true )
                {
                    // Yes( ProductName is set in AssemblyInfo )
                    MessageBox.Show( strMessageToLog, Application.ProductName, 
                                    MessageBoxButtons.OK, MessageBoxIcon.Warning );
                }

                // Append a date/time stamp
                strMessageToLog = ( DateTime.Now ).ToString( "yyyy/MM/dd HH:mm:ss" ) 
                                  + " - " + strMessageToLog + Environment.NewLine +
                                  Environment.NewLine;

                // Get a free file handle
                fsLogFile = GetLogFile( );

                // Is the file OK?
                if( fsLogFile != null )
                {
                    // Yes, Log it
                    fsLogFile.Write( encConvertToByteArray.GetBytes( strMessageToLog ), 
                                     0, strMessageToLog.Length );

                    // Flush the buffer so we can immediately see results in file.  Very important.
                    // Otherwise we have to wait for flush which might be when application closes
                    // or we get another error.  Waiting for the application to close may not be
                    // a good idea if the application is in a production environment ( e.g. a web
                    //  app running on a remote server )
                    fsLogFile.Flush( );
                }
            }
            catch( Exception excError )
            {
                // Display error message
                MessageBox.Show( "Error:\n" + excError.ToString( ), Application.ProductName,
                                MessageBoxButtons.OK, MessageBoxIcon.Warning );
            }
        }


        // -------------------------------------------------------------------------
        // Name: DeleteOldFiles
        // Abstract: Delete any files older than 10 days.
        // -------------------------------------------------------------------------
        private static void DeleteOldFiles( )
        {
            try
            {
                String strLogFilePath = "";
                DirectoryInfo dirLogDirectory = null;
                DateTime dtmFileCreated = DateTime.Now;
                int intDaysOld = 0;

                // Path
                strLogFilePath = Application.StartupPath + "\\Log\\";

                // Look for any files
                dirLogDirectory = new DirectoryInfo( strLogFilePath );

                // Are there any?
                foreach( FileInfo finLogFile in dirLogDirectory.GetFiles( "*" + strLOG_FILE_EXTENSION ) )
                {
                    // When was the file created?
                    dtmFileCreated = finLogFile.CreationTime;

                    // How old is the file?
                    intDaysOld = ( dtmFileCreated.Subtract( DateTime.Now ) ).Days;

                    // Is the file older than 10 days?
                    if( intDaysOld > 10 )
                    {
                        // Yes.  Delete it.
                        finLogFile.Delete( );
                    }

                }

            }
            catch( Exception excError )
            {
                // Display error message
                MessageBox.Show( "Error:\n" + excError.ToString( ), Application.ProductName,
                                MessageBoxButtons.OK, MessageBoxIcon.Warning );
            }
        }


        // -------------------------------------------------------------------------
        // Name: GetLogFile
        // Abstract: Open the log file for writing.  Use today's date as part of
        //           the file name.  Each day a new log file will be created.
        //           Makes debug easier.
        //           Use a filestream object so we can specify file read share
        //           during the open call.
        // -------------------------------------------------------------------------
        private static FileStream GetLogFile( ) 
        {
            try
            {
                String strToday = ( DateTime.Now ).ToString( "yyyyMMdd" );
                String strLogFilePath = "";

                // Log everything in a log directory off of the current application directory
                strLogFilePath = Application.StartupPath + "\\Log\\" + strToday + strLOG_FILE_EXTENSION;

                // Is this a new day?
                if ( m_strOldLogFilePath != strLogFilePath )
                {
                    // Save the log file name
                    m_strOldLogFilePath = strLogFilePath;

                    // Does the log directory exist?
                    if ( Directory.Exists( Application.StartupPath + "\\Log" ) == false )
                    {
                        // No, so create it
                        Directory.CreateDirectory( Application.StartupPath + "\\Log" );
                    }

                    // Close old log file( if there is one )
                    if ( m_fsLogFile != null ) m_fsLogFile.Close( );

                    // Delete old log files
                    DeleteOldFiles( );

                    // Does the file exist?
                    if ( File.Exists( strLogFilePath ) == false )
                    {
                        // No, create with shared read access so it can be read while application has it open
                        m_fsLogFile = new FileStream( strLogFilePath, FileMode.Create,
                                                      FileAccess.Write, FileShare.Read );
                    }
                    else
                    {
                        // Yes, append with shared read access so it can be read while application has it open
                        m_fsLogFile = new FileStream( strLogFilePath, FileMode.Append,
                                                      FileAccess.Write, FileShare.Read );
                    }
                }
            }
            catch( Exception excError )
            {
                // Display error message
                MessageBox.Show( "Error:\n" + excError.ToString( ), Application.ProductName,
                                MessageBoxButtons.OK, MessageBoxIcon.Warning );
            }

            return m_fsLogFile;
        }
    }
}
