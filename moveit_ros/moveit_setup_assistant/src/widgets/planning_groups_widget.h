/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Dave Coleman */

#ifndef MOVEIT_ROS_MOVEIT_SETUP_ASSISTANT_WIDGETS_PLANNING_GROUPS_WIDGET_
#define MOVEIT_ROS_MOVEIT_SETUP_ASSISTANT_WIDGETS_PLANNING_GROUPS_WIDGET_

#include <QWidget>
#include <QTreeWidget>
#include <QSplitter>
#include <QStackedLayout>
#include "moveit_setup_assistant/tools/moveit_config_data.h"
#include "joint_collection_widget.h"
#include "setup_screen_widget.h" // a base class for screens in the setup assistant

// Forward Declaration
class PlanningGroupsTableWidget;


// ******************************************************************************************
// ******************************************************************************************
// CLASS
// ******************************************************************************************
// ******************************************************************************************
class PlanningGroupsWidget : public SetupScreenWidget
{
  Q_OBJECT

  public:
  // ******************************************************************************************
  // Public Functions
  // ******************************************************************************************

  PlanningGroupsWidget( QWidget *parent, moveit_setup_assistant::MoveItConfigDataPtr config_data );

  void changeScreen( int index );

  /// Recieved when this widget is chosen from the navigation menu
  virtual void focusGiven();

private Q_SLOTS:

  // ******************************************************************************************
  // Slot Event Functions
  // ******************************************************************************************

  /// Displays data in the link_pairs_ data structure into a QtTableWidget
  void loadGroupsTree();

  /// Edit whatever element is selected in the tree view
  void editSelected();

  /// Create a new, empty group
  void addGroup();

  /// This is called when a child screen (add/edit screens) are ready to come back to main screen
  void doneEditing();

  /// Called when user clicks link part of bottom left label
  void alterTree( const QString &link );

private:

  // ******************************************************************************************
  // Qt Components
  // ******************************************************************************************

  /// For changing between table and different add/edit views
  QStackedLayout *stacked_layout_;

  /// Subpages for types of planning groups
  JointCollectionWidget *joints_widget_;

  /// Main contents widget
  QWidget *groups_tree_widget_;

  /// Main table for holding groups
  QTreeWidget *groups_tree_;

  // ******************************************************************************************
  // Variables
  // ******************************************************************************************

  /// Contains all the configuration data for the setup assistant
  moveit_setup_assistant::MoveItConfigDataPtr config_data_;

  // ******************************************************************************************
  // Private Functions
  // ******************************************************************************************

  
  QWidget* createContentsWidget();

  /// Recursively build the SRDF tree
  void addLinkToTreeRecursive( const srdf::Model::Group &group_it, QTreeWidgetItem *parent );

};


#endif
