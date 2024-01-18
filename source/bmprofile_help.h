const char bmprofile_help[] = {
  "# BlackMagic Profiler\n"
  "\n"
  "A sampling profiler using SWO (Serial Wire Output) for non-intrusive profiling.\n"
  "The utility requires that the firmware (that runs on the target device) is built\n"
  "with debug information, but in many cases does not require changes to the source\n"
  "code.\n"
  "\n"
  "The user interface of the Profiler has a button bar on top, and the main view\n"
  "on the left.\n"
  "\n"
  "At the right is a sidebar for settings & status with TAB panels that can be\n"
  "folded in or out:\n"
  " [[Configuration]]\n"
  " [[Profile options]]\n"
  " [[Status]]\n"
  "\n"
  "---\n"
  "Miscellaneous information:\n"
  " [[The Button Bar]]\n"
  " [[The Profile Graph]]\n"
  " [[About BlackMagic Profiler]]\n"
  "\n"
  "# The Button Bar\n"
  "\n"
  "*Start / Stop*\n"
  ": The Start button starts capturing the sample data, and the Stop button stops\n"
  " the capture. When running, the label on the button changes from \"Start\" to\n"
  " \"Stop,\" and after stopping, the button is relabeled back to \"Start.\"\n"
  "\n"
  ": Note that if you change any of the configuration options in the sidebar, you\n"
  " may need to stop and re-start the sampling, in order to let the Profiler re-configure\n"
  " the debug probe.\n"
  "\n"
  ": You can also use function key F5 to start or stop profiling.\n"
  "\n"
  "*Clear*\n"
  ": Clears the profiling graph and all sampling data.\n"
  "\n"
  "*Save*\n"
  ": Stores the sampling data in a CSV file (Comma Separated Values). You can open\n"
  " these files in a spreadsheet program (Excel, LibreOffice Calc, ...) for further\n"
  " analysis.\n"
  "\n"
  ": Note that the program always stores the full sampling data, and at the granularity\n"
  " of a source line. That is, the current view in the profile graph does not affect\n"
  " the format or contents of the data.\n"
  "\n"
  "*Help*\n"
  ": Opens up the on-line help that you are reading now.\n"
  "\n"
  "---\n"
  "See also:\n"
  " [[The Profile Graph]]\n"
  " [[Configuration]]\n"
  " [[Profile options]]\n"
  "\n"
  "# The Profile Graph\n"
  "\n"
  "After startup, the graph shows the list of all functions in the ELF file. Each\n"
  "function has a bar to the left, as a indication of number of samples in that\n"
  "function's address range. The percentage is also displayed. The function list\n"
  "is sorted from \"most sampled\" to \"least sampled.\"\n"
  "\n"
  "After a mouse-click on a function name, utility zooms in on the function. It\n"
  "shows the source lines of the function, plus bars on the left to indicate the\n"
  "number of samples on each source line. The source lines are, of course, not\n"
  "sorted.\n"
  "\n"
  "A mouse-click on any line in the source view, returns to the main function-level\n"
  "view.\n"
  "\n"
  "---\n"
  "See also:\n"
  " [[Configuration]]\n"
  " [[Status]]\n"
  "\n"
  "# Configuration\n"
  "\n"
  "The Configuration view is an expandable panel in the sidebar at the right. It\n"
  "contains the following settings:\n"
  "\n"
  "*Probe*\n"
  ": The debug probe to use. If only a single probe is connected to the work~station,\n"
  " it will be automatically selected. Otherwise, you can select it from the drop-down\n"
  " list.\n"
  "\n"
  ": In the case of a ctxLink probe configured for Wi-Fi, you select \"TCP/IP\" from\n"
  " this list.\n"
  "\n"
  "*IP Addr*\n"
  ": This option is only visible when \"TCP/IP\" is selected from the drop-down list\n"
  " of the preceding \"Probe\" option. Here, you can fill in the IP address that\n"
  " the debug probe (likely a ctxLink probe) is configured at. Alternatively,\n"
  " you can click on the \"...\" button at the right of the edit field, to let the\n"
  " utility scan the network for the debug probe.\n"
  "\n"
  "*Mode*\n"
  ": Either Manchester or NRZ (asynchronous). Which mode to use, depends on the\n"
  " particular debug probe: the original Black Magic Probe supports only Manchester,\n"
  " while the ctxLink probe supports only NRZ. If the Profiler detects the type of\n"
  " debug probe, this field is updated automatically.\n"
  "\n"
  "*Configure Target*\n"
  ": If selected, the Profiler configures the microcontroller on the target device\n"
  " for SWO tracing. For this to work, the Profiler must have support for the\n"
  " particular microcontroller. The Profiler supports several microcontroller\n"
  " families out of the box, and more can be added.\n"
  "\n"
  "*Configure Debug Probe*\n"
  ": If selected, the Profiler configures the Black Magic Probe for capturing\n"
  " SWO tracing.\n"
  "\n"
  ": If neither this option, nor the option \"Configure Target\" are set, the Profiler\n"
  " does not open a connection with the debug interface of the Black Magic Probe.\n"
  " This allows you to control the debug probe and the target with another program\n"
  " (such as GDB) while sampling performance data with the Profiler.\n"
  "\n"
  "*Reset target during connect*\n"
  ": This option may be needed on some microcontrollers, especially if SWD pins get\n"
  " redefined.\n"
  "\n"
  "*CPU clock*\n"
  ": The clock of the microcontroller in Hz. This value is needed when the Profiler\n"
  " configures the target.\n"
  "\n"
  "*Bit rate*\n"
  ": The transfer speed in bits/second. This value is needed when the Profiler\n"
  " configures the target (it may also be needed for configuring the debug probe,\n"
  " depending on the mode).\n"
  "\n"
  "*ELF file*\n"
  ": The ELF file is needed to map sampled addresses to source code lines and\n"
  " functions. The ELF file that is set in this field, must of course match the\n"
  " firmware loaded into the target.\n"
  "\n"
  "---\n"
  "See also:\n"
  " [[Profile options]]\n"
  "\n"
  "# Profile options\n"
  "\n"
  "Profile options are in an expandable panel in the sidebar at the right. It\n"
  "contains the following settings:\n"
  "\n"
  "*Sample rate*\n"
  ": The desired sample rate in Hz. A value of 1000 means 1000 samples per second.\n"
  "\n"
  ": The actual sample rate depends on the configuration of the microcontroller. The\n"
  " true (detected) sample rate is printed in the Status panel.\n"
  "\n"
  "*Refresh interval*\n"
  ": The delay, in seconds, between two refreshes of the graph. A fractional value\n"
  " is allowed; you can set the delay to 0.5 to get two refreshes per second.\n"
  "\n"
  "*Accumulate samples*\n"
  ": If active, the graph totals the samples from the beginning of the profiling\n"
  " run. The longer it runs, the more accurate the profiling data becomes.\n"
  "\n"
  ": If not active, the graph shows the sampling distribution since the last\n"
  " refresh. In other words, when the refresh is set to 1 second, the graph is\n"
  " updated each second with the sampling data of the past second. The graph is\n"
  " therefore more dynamic, and shows where the firmware spends time at that\n"
  " instant.\n"
  "\n"
  "---\n"
  "See also:\n"
  " [[Configuration]]\n"
  " [[Status]]\n"
  "\n"
  "# Status\n"
  "\n"
  "The Status view is an expandable panel in the sidebar at the right. It contains\n"
  "the following values:\n"
  "\n"
  "*Real sampling rate*\n"
  ": The measured sampling rate. This value should be close to the sampling rate\n"
  " set in the Profile options.\n"
  "\n"
  "*Overflow events*\n"
  ": When the overflow event count is non-zero, sampling data arrives more quickly\n"
  " than can be processed. The sampling rate should be reduced.\n"
  "\n"
  "*Overhead*\n"
  ": This value refers to samples that have addresses that fall outside the memory\n"
  " range that the ELF file takes. This may indicate that the microcontroller is\n"
  " running code in ROM routines.\n"
  "\n"
  "---\n"
  "See also:\n"
  " [[Profile options]]\n"
  "\n"
  "# About BlackMagic Profiler\n"
  "\n"
  "The BlackMagic Profiler is a companion tool of the book \"Embedded Debugging\n"
  "with the Black Magic Probe.\" The book has a chapter on profiling, discussing the\n"
  "pros and cons of sampling versus instrumented profiling, plus notes on diving\n"
  "deeper into the profile analysis. It is available as a free PDF file, and\n"
  "as a printed book.\n"
  "\n"
  "The BlackMagic Profiler requires a debug probe that is compatible with the\n"
  "Black Magic Probe. It is a self-contained utility; it does not require GDB.\n"
  "\n"
  "---\n"
  "Version 1.2.7084 \\\n"
  "Copyright 2022-2024 CompuPhase \\\n"
  "Licensed under the Apache License version 2.0\n"
  "\n"
};
