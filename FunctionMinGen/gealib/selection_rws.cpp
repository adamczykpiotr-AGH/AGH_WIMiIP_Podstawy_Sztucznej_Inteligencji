#include "selection_rws.h"
#include <vector>
#include <algorithm>
#include "typedefs.h"

void gealib::selection_rws::select(chromo_vec & current, chromo_vec & selected) {
	size_t count = selected.size();
	std::vector<ftype> values;
	values.reserve(current.size());
	ftype minv = FLT_MAX;
	std::for_each(current.begin(), current.end(), [&minv, &values](chromo_ptr p){
		ftype f = p->fitness;
		values.push_back(f); 
		minv = std::min(minv, f); 
	});

	ftype fsum = 0;
	std::for_each(values.begin(), values.end(), [&fsum, minv](ftype& val) {
		val += (fsum - minv);
		fsum = val;
	});

	for (int i = 0; i < count; i++)	{
		ftype d = random_generator::get_float(0, fsum);
		auto it = std::lower_bound(values.begin(), values.end(), d);
		size_t idx = it - values.begin();
		selected[i] = current[idx];
	}
}