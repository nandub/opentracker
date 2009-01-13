/* This software was written by Dirk Engling <erdgeist@erdgeist.org>
   It is considered beerware. Prost. Skol. Cheers or whatever.

   $id$ */

#ifndef __OT_ACCESSLIST_H__
#define __OT_ACCESSLIST_H__

#if defined ( WANT_ACCESSLIST_BLACK ) && defined (WANT_ACCESSLIST_WHITE )
#  error WANT_ACCESSLIST_BLACK and WANT_ACCESSLIST_WHITE are exclusive.
#endif

#if defined ( WANT_ACCESSLIST_BLACK ) || defined (WANT_ACCESSLIST_WHITE )
#define WANT_ACCESSLIST
void accesslist_init( );
void accesslist_deinit( );
int  accesslist_hashisvalid( ot_hash hash );

extern char *g_accesslist_filename;

#else
#define accesslist_init( accesslist_filename )
#define accesslist_deinit( )
#define accesslist_hashisvalid( hash ) 1
#endif

typedef enum {
  OT_PERMISSION_MAY_FULLSCRAPE = 0x1,
  OT_PERMISSION_MAY_STAT       = 0x2,
  OT_PERMISSION_MAY_LIVESYNC   = 0x4
} ot_permissions;

int  accesslist_blessip( ot_ip6 ip, ot_permissions permissions );
int  accesslist_isblessed( ot_ip6 ip, ot_permissions permissions );

#endif
