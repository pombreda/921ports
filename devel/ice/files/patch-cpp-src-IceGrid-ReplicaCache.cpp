--- cpp.orig/src/IceGrid/ReplicaCache.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceGrid/ReplicaCache.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -40,7 +40,7 @@
     Lock sync(*this);
     
     ReplicaEntryPtr entry;
-    while(entry = getImpl(name))
+    while((entry = getImpl(name)))
     {
         ReplicaSessionIPtr session = entry->getSession();
         if(session->isDestroyed())
