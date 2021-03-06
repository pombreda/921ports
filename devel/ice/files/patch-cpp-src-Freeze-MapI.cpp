--- cpp.orig/src/Freeze/MapI.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Freeze/MapI.cpp	2012-03-04 20:14:52.000000000 +0100
@@ -749,8 +749,11 @@
 
     try
     {
+#ifndef NDEBUG
         int err;
-        err = _dbc->put(&dbKey, &dbValue, DB_CURRENT);
+        err = 
+#endif
+        _dbc->put(&dbKey, &dbValue, DB_CURRENT);
         assert(err == 0);
     }
     catch(const ::DbDeadlockException& dx)
@@ -1023,7 +1026,11 @@
 #ifndef NDEBUG
         bool inserted =
 #endif 
-            _indices.insert(IndexMap::value_type(indexBase->name(), indexBase)).second;
+            _indices.insert(IndexMap::value_type(indexBase->name(), indexBase))
+#ifndef NDEBUG
+            .second
+#endif
+            ;
         assert(inserted);
         indexBase->_map = this;
     }
@@ -1360,8 +1367,11 @@
         try
         {
             u_int32_t count;
+#ifndef NDEBUG
             int err;
-            err = _db->truncate(txn, &count, txn != 0 ? 0 : DB_AUTO_COMMIT);
+            err = 
+#endif            
+            _db->truncate(txn, &count, txn != 0 ? 0 : DB_AUTO_COMMIT);
             assert(err == 0);
             break;
         }
