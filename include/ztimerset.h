/*  =========================================================================
    ztimerset - timer set

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of CZMQ, the high-level C binding for 0MQ:
    http://czmq.zeromq.org.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef ZTIMERSET_H_INCLUDED
#define ZTIMERSET_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/ztimerset.api" to make changes.
//  @interface
//  This is a draft class, and may change without notice. It is disabled in
//  stable builds by default. If you use this in applications, please ask
//  for it to be pushed to stable state. Use --enable-drafts to enable.
#ifdef CZMQ_BUILD_DRAFT_API
// Callback function for timer event.
typedef void (ztimerset_fn) (
    int timer_id, void *arg);

//  *** Draft method, for development use, may change without warning ***
//  Create new timer set.
CZMQ_EXPORT ztimerset_t *
    ztimerset_new (void);

//  *** Draft method, for development use, may change without warning ***
//  Destroy a timer set
CZMQ_EXPORT void
    ztimerset_destroy (ztimerset_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//  Add a timer to the set. Returns timer id if OK, -1 on failure.
CZMQ_EXPORT int
    ztimerset_add (ztimerset_t *self, size_t interval, ztimerset_fn handler, void *arg);

//  *** Draft method, for development use, may change without warning ***
//  Cancel a timer. Returns 0 if OK, -1 on failure.
CZMQ_EXPORT int
    ztimerset_cancel (ztimerset_t *self, int timer_id);

//  *** Draft method, for development use, may change without warning ***
//  Set timer interval. Returns 0 if OK, -1 on failure.
//  This method is slow, canceling the timer and adding a new one yield better performance.
CZMQ_EXPORT int
    ztimerset_set_interval (ztimerset_t *self, int timer_id, size_t interval);

//  *** Draft method, for development use, may change without warning ***
//  Reset timer to start interval counting from current time. Returns 0 if OK, -1 on failure.
//  This method is slow, canceling the timer and adding a new one yield better performance.
CZMQ_EXPORT int
    ztimerset_reset (ztimerset_t *self, int timer_id);

//  *** Draft method, for development use, may change without warning ***
//  Return the time until the next interval.
//  Should be used as timeout parameter for the zpoller wait method.
//  The timeout is in msec.
CZMQ_EXPORT int
    ztimerset_timeout (ztimerset_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Invoke callback function of all timers which their interval has elapsed.
//  Should be call after zpoller wait method.
//  Returns 0 if OK, -1 on failure.
CZMQ_EXPORT int
    ztimerset_execute (ztimerset_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Self test of this class.
CZMQ_EXPORT void
    ztimerset_test (bool verbose);

#endif // CZMQ_BUILD_DRAFT_API
//  @end

#ifdef __cplusplus
}
#endif

#endif
