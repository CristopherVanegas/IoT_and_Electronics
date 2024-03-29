KiCad
=====
KiCad is an EDA software suite for the creation of professional schematics and printed circuit boards up to 32 copper layers. KiCad runs on Windows, Linux and macOS and is released free of charge under the open-source GNU GPL v2 license.  KiCad comes with a rich set of libraries including 3D models.

KiCad is a mature EDA software tool under active development by a team of developers and a vibrant user group.

KiCad targets the current version of macOS with support back to macOS 10.11.

Installing
==========
If you have already installed KiCad before the V5 release, you may need to upgrade a little differently. Please see the Upgrading section.

To install KiCad, click and drag the two directory icons to the targets pointed at by the arrows.

After dropping kicad onto Application Support, you may be asked to authenticate with an administrator username and password.  This installs the support files for KiCad for all users on the system.

KiCad is now installed!  Inside of /Applications will be a directory called KiCad, and inside of that are all the programs in KiCad.  The project manager is the one labeled kicad, and is probably where you want to start.

When you open the KiCad apps the first time, you must right-click on them and select Open.  You only need to do this once.  You must open KiCad first before opening the standalone apps, or else the standalone apps won't be able to open up due to macOS quarantining.

Upgrading
=========

Read these notes first, before following the Installing section.

* In general, please see http://kicad.org/help/migration/ when upgrading KiCad to new major version (i.e. V4 to V5).
* Your footprint table will need to be upgraded.  Instructions are located at http://docs.kicad.org/master/en/kicad.html#_upgrading_from_version_4_to_version_5.
* Although it is easy to have both the KiCad V4 and V5 applications installed at the same time, by default, they read from the same location for support files like footprints and symbols.  Because of this, you may want to backup your KiCad installation before upgrading to V5.  The backup-kicad script in this disk image will attempt to do this.  Right-click on the backup-kicad file, and select Open to run it and create a backup into your home directory.
* If you have a directory called Kicad in your Applications directory, and you have a case-insensitive drive (which is the default in macOS), you will need to either rename or delete the directory before dragging the new KiCad directory into Applications, or you'll get an error.

Demos and Example Files
=======================
There are example projects and example Python scripts in the demos directory of the DMG.  Feel free to copy them outside of the DMG and use them.

Unified, Nightly, and Extras
============================
There are three different DMGs for KiCad on macOS.

Unified contains the KiCad application and the official symbols, footprints, 3D models and docs.

Nightly does not contain the 3D models and docs, they are large, and the nightlies are intended for users who want to test changes on a daily basis.

Extras contains only the 3D models and docs.

Documentation
=============
Documentation is available online at http://kicad.org/help/documentation/.  It is also available inside the various KiCad programs under the Help menu, and after installing from this disk image, is also available at /Library/Application Support/kicad/help.

Reporting Issues
================
The KiCad developers work hard to provide quality releases to our users.

If you encounter issues with this software, please report a bug at https://bugs.launchpad.net/kicad.

By including both the KiCad version information, and your computer's version information, you help the developers quickly fix the issue. This is done by clicking the "Copy Version Information" button in the About window from the application that has the bug, and then pasting into the bug report.  Additionally, please open a Terminal and run the following command:

    sw_vers

and then copy and paste the output into the bug report as well.

Uninstalling
============
To uninstall KiCad, delete /Applications/KiCad.

Additionally, support files for KiCad may be located in:

* /Library/Application Support/kicad
* ~/Library/Application Support/kicad

Preferences may be stored in:

* Library/Preferences/org.kicad-pcb.*
* Library/Preferences/kicad
