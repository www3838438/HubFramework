/*
 *  Copyright (c) 2016 Spotify AB.
 *
 *  Licensed to the Apache Software Foundation (ASF) under one
 *  or more contributor license agreements.  See the NOTICE file
 *  distributed with this work for additional information
 *  regarding copyright ownership.  The ASF licenses this file
 *  to you under the Apache License, Version 2.0 (the
 *  "License"); you may not use this file except in compliance
 *  with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 *  specific language governing permissions and limitations
 *  under the License.
 */

#import "HUBComponent.h"

@protocol HUBAction;
@protocol HUBActionContext;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Extended component protocol that adds the ability to observe whenever an action was performed
 *
 *  You can use this protocol to be able to react to an action being performed in your component.
 *
 *  See `HUBComponent` and `HUBAction` for more information.
 */
@protocol HUBComponentActionObserver <HUBComponent>

/**
 *  Sent to a component whenever an action was performed in the view that it is being used in
 *
 *  @param context The contextual object that the action was performed with
 *
 *  The Hub Framework will call this method on your component every time that an action was performed
 *  in the view that it is being used in, including both default selection actions & custom ones.
 */
- (void)actionPerformedWithContext:(id<HUBActionContext>)context;

@end

NS_ASSUME_NONNULL_END
