file(REMOVE_RECURSE
  "libdependencies.a"
  "libdependencies.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/dependencies.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
