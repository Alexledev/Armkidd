from watchdog.observers.polling import PollingObserver as Observer
# from watchdog.observers import Observer

def runFileWatcher(eventHandler, watchPath="./"):

    observer = Observer()
    observer.schedule(eventHandler, path=watchPath, recursive=False)

    observer.start()
    try:
        observer.join()
    finally:
        observer.stop()
        observer.join()