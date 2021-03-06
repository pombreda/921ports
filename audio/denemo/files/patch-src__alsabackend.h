--- src/alsabackend.h
+++ src/alsabackend.h
@@ -0,0 +1,23 @@
+/*
+ * alsabackend.h
+ * ALSA sequencer MIDI backend.
+ *
+ * for Denemo, a gtk+ frontend to GNU Lilypond
+ * Copyright (C) 2011  Dominic SacrÃ©
+ *
+ * This program is free software: you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation, either version 3 of the License, or
+ * (at your option) any later version.
+ */
+
+#ifndef ALSABACKEND_H
+#define ALSABACKEND_H
+
+#include "audiointerface.h"
+
+extern backend_t alsa_seq_midi_backend;
+
+
+#endif // ALSABACKEND_H
+
