//
//  Cinder.AppleMusicPlayer.h
//  Cinder.AppleMusic
//
//

#pragma once

#include "CinderAppleMusicPlayerImpl.h"
#include "CinderAppleMusic.h"

namespace cinder { namespace AppleMusic {
    
    class Player {
    public:
        
        enum State {
            StateStopped         = MPMusicPlaybackStateStopped,
            StatePlaying         = MPMusicPlaybackStatePlaying,
            StatePaused          = MPMusicPlaybackStatePaused,
            StateInterrupted     = MPMusicPlaybackStateInterrupted,
            StateSeekingForward  = MPMusicPlaybackStateSeekingForward,
            StateSeekingBackward = MPMusicPlaybackStateSeekingBackward
        };
        
        Player();
        ~Player();
        
        void play( TrackRef playlist );
        void play( PlaylistRef playlist );
        void play( PlaylistRef playlist, const int index );
        void play();
        void pause();
        void stop();
        void skipNext();
        void skipPrev();
        
        void   setPlayheadTime(double time);
        double getPlayheadTime();
        
        void setShuffleSongs();
        void setShuffleAlbums();
        void setShuffleOff();
        
        bool hasPlayingTrack();
        TrackRef getPlayingTrack();
        State    getPlayState();
        
        template<typename T>
        CallbackId registerTrackChanged( T *obj, bool (T::*callback)(Player*) ){
            return am_pod->am_cb_track_change.registerCb(std::bind1st(std::mem_fun(callback), obj));
        }
        template<typename T>
        CallbackId registerStateChanged( T *obj, bool (T::*callback)(Player*) ){
            return am_pod->am_cb_state_change.registerCb(std::bind1st(std::mem_fun(callback), obj));
        }
        template<typename T>
        CallbackId registerLibraryChanged( T *obj, bool (T::*callback)(Player*) ){
            return am_pod->am_cb_library_change.registerCb(std::bind1st(std::mem_fun(callback), obj));
        }
        
    protected:
        
        CinderAppleMusicPlayerImpl *am_pod;
        
    };
    
} }
